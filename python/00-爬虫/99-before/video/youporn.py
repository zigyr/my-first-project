import os
import re
import sys
import time
import json
import shutil
import random
import logging
import warnings
from typing import Dict, List, Optional, Tuple, Set
from dataclasses import dataclass, field
from urllib.parse import urljoin

import aiohttp
import aiofiles
import asyncio
from aiohttp import ClientTimeout, TCPConnector
from urllib3.exceptions import InsecureRequestWarning

# ===================== 1. 全局配置（异步优化版） =====================
warnings.filterwarnings("ignore", category=InsecureRequestWarning)

# 日志配置
LOG_LEVEL = logging.INFO
LOG_FORMAT = "%(asctime)s - %(name)s - %(levelname)s - %(message)s"
LOG_FILE = "m3u8_async_downloader.log"

logging.basicConfig(
    level=LOG_LEVEL,
    format=LOG_FORMAT,
    handlers=[
        logging.FileHandler(LOG_FILE, encoding="utf-8"),
        logging.StreamHandler(sys.stdout)
    ]
)
logger = logging.getLogger("AsyncM3U8Downloader")

# 定义目标存储目录（项目根目录下的prohub）
PROJECT_ROOT = os.path.dirname(os.path.abspath(__file__))  # 获取当前脚本所在目录（项目根目录）
TARGET_DIR = os.path.join(PROJECT_ROOT, "prohub")  # 目标文件夹：项目根目录/prohub
os.makedirs(TARGET_DIR, exist_ok=True)  # 确保目录存在


# 异步下载配置（核心：增大并发+降低延迟）
@dataclass
class AsyncDownloadConfig:
    batch_size: int = 20  # 每批次分片数（异步可翻倍）
    batch_sleep: float = 8.0  # 批次间暂停（异步可减少）
    per_task_sleep: float = 0.1  # 任务间最小延迟（毫秒级）
    max_concurrent: int = 10  # 异步最大并发数（核心提速）
    chunk_size: int = 1024 * 4096  # 超大块IO（提升写入速度）
    retry_times: int = 3  # 重试次数
    timeout: float = 30.0  # 超时时间（异步可缩短）
    user_agents: List[str] = field(default_factory=lambda: [
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/143.0.0.0 Safari/537.36",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 14_5) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/17.5 Safari/605.1.15",
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Edge/142.0.2478.97"
    ])
    enable_breakpoint: bool = True  # 断点续传
    enable_rate_limit: bool = False  # 速率限制（抗风控）
    rate_limit: float = 5.0  # 限速（MB/s）
    forbidden_chars: Tuple[str, ...] = ("/", "\\", ":", "*", "?", "\"", "<", ">", "|")


# ===================== 2. 自定义异常 =====================
class M3U8DownloadError(Exception):
    pass


class InvalidURLError(M3U8DownloadError):
    pass


class M3U8ParseError(M3U8DownloadError):
    pass


class TSMergeError(M3U8DownloadError):
    pass


class DownloadTimeoutError(M3U8DownloadError):
    pass


# ===================== 3. 工具类 =====================
class AsyncUtils:
    @staticmethod
    def is_valid_url(url: str) -> bool:
        if not isinstance(url, str) or not url.strip():
            return False
        return url.strip().startswith(("http://", "https://"))

    @staticmethod
    def sanitize_filename(filename: str, forbidden_chars: Tuple[str, ...]) -> str:
        for char in forbidden_chars:
            filename = filename.replace(char, "_")
        return filename.strip()

    @staticmethod
    def load_config(config_path: str = "async_download_config.json") -> AsyncDownloadConfig:
        if not os.path.exists(config_path):
            logger.warning(f"配置文件{config_path}不存在，使用默认配置")
            return AsyncDownloadConfig()

        try:
            with open(config_path, "r", encoding="utf-8") as f:
                config_dict = json.load(f)
            return AsyncDownloadConfig(** config_dict)
        except Exception as e:
            logger.error(f"加载配置失败：{e}，使用默认配置")
            return AsyncDownloadConfig()

    @staticmethod
    def get_file_size(file_path: str, human_readable: bool = True) -> str | int:
        if not os.path.exists(file_path):
            return 0 if not human_readable else "0B"

        size = os.path.getsize(file_path)
        if not human_readable:
            return size

        units = ["B", "KB", "MB", "GB", "TB"]
        idx = 0
        while size >= 1024 and idx < len(units) - 1:
            size /= 1024
            idx += 1
        return f"{size:.2f}{units[idx]}"


# ===================== 4. 核心异步下载器（修复Session问题） =====================
class AsyncM3U8Downloader:
    def __init__(self, config: Optional[AsyncDownloadConfig] = None):
        self.config = config or AsyncDownloadConfig()
        self.temp_dir: Optional[str] = None
        self.downloaded_ts: Set[int] = set()
        self.semaphore: Optional[asyncio.Semaphore] = None  # 并发控制信号量
        self.rate_limiter: Optional[asyncio.Semaphore] = None  # 速率限制

    def _init_temp_dir(self, video_title: str) -> None:
        """初始化临时目录（断点续传）- 移到prohub文件夹下"""
        sanitized_title = AsyncUtils.sanitize_filename(video_title, self.config.forbidden_chars)
        # 临时目录改为：prohub/temp_async_视频标题
        self.temp_dir = os.path.join(TARGET_DIR, f"temp_async_{sanitized_title}")

        if self.config.enable_breakpoint and os.path.exists(self.temp_dir):
            self.downloaded_ts = set(
                int(f.split("_")[1].split(".")[0])
                for f in os.listdir(self.temp_dir)
                if f.startswith("ts_") and f.endswith(".ts") and os.path.getsize(os.path.join(self.temp_dir, f)) > 0
            )
            logger.info(f"断点续传：已下载{len(self.downloaded_ts)}个分片")
        else:
            os.makedirs(self.temp_dir, exist_ok=True)

    async def _parse_m3u8(self, m3u8_url: str, proxies: Optional[str] = None) -> List[Tuple[int, str]]:
        """异步解析M3U8"""
        if not AsyncUtils.is_valid_url(m3u8_url):
            raise InvalidURLError(f"非法URL：{m3u8_url}")

        timeout = ClientTimeout(total=self.config.timeout)
        connector = TCPConnector(ssl=False)

        try:
            # 独立Session解析M3U8（避免复用问题）
            async with aiohttp.ClientSession(timeout=timeout, connector=connector) as session:
                referer = m3u8_url.rsplit("/", 1)[0]
                headers = {
                    "User-Agent": random.choice(self.config.user_agents),
                    "Referer": referer
                }

                async with session.get(m3u8_url, headers=headers, proxy=proxies) as resp:
                    resp.raise_for_status()
                    m3u8_text = await resp.text()

            # 提取TS路径
            ts_pattern = re.compile(r'^[^#].*\.ts.*$', re.MULTILINE)
            ts_relative_paths = [p.strip() for p in ts_pattern.findall(m3u8_text) if p.strip()]

            if not ts_relative_paths:
                raise M3U8ParseError("未提取到TS分片")

            # 拼接完整URL
            ts_full_paths = []
            for idx, path in enumerate(ts_relative_paths):
                full_url = urljoin(m3u8_url, path)
                if AsyncUtils.is_valid_url(full_url):
                    ts_full_paths.append((idx, full_url))

            if not ts_full_paths:
                raise M3U8ParseError("无合法TS分片")

            logger.info(f"M3U8解析完成：共{len(ts_full_paths)}个分片")
            return ts_full_paths

        except asyncio.TimeoutError:
            raise DownloadTimeoutError(f"M3U8请求超时（{self.config.timeout}秒）")
        except Exception as e:
            raise M3U8ParseError(f"解析失败：{str(e)[:100]}")

    async def _download_single_ts(self, ts_info: Tuple[int, str], proxies: Optional[str] = None):
        ts_idx, ts_url = ts_info
        if ts_idx in self.downloaded_ts:
            logger.debug(f"跳过已下载分片：{ts_idx}")
            return True

        async with self.semaphore:
            if self.config.enable_rate_limit:
                async with self.rate_limiter:
                    await asyncio.sleep(0.001)

            ts_filename = f"ts_{ts_idx:06d}.ts"
            ts_save_path = os.path.join(self.temp_dir, ts_filename)
            temp_file = f"{ts_save_path}.tmp"

            for retry in range(self.config.retry_times):
                try:
                    # 核心修改：每个请求使用全新的TCPConnector（禁用连接复用）
                    timeout = ClientTimeout(total=self.config.timeout)
                    connector = TCPConnector(ssl=False, force_close=True)  # 强制关闭连接
                    headers = {
                        "User-Agent": random.choice(self.config.user_agents),
                        "Referer": ts_url.rsplit("/", 1)[0],
                        "Connection": "close"
                    }

                    async with aiohttp.ClientSession(timeout=timeout, connector=connector) as session:
                        async with session.get(ts_url, headers=headers, proxy=proxies) as resp:
                            resp.raise_for_status()
                            async with aiofiles.open(temp_file, "wb") as f:
                                async for chunk in resp.content.iter_chunked(self.config.chunk_size):
                                    if chunk:
                                        await f.write(chunk)

                    # 显式关闭connector（释放资源）
                    await connector.close()

                    os.rename(temp_file, ts_save_path)
                    self.downloaded_ts.add(ts_idx)
                    await asyncio.sleep(self.config.per_task_sleep)
                    logger.debug(f"分片{ts_idx}下载成功（重试{retry}次）")
                    return True

                except Exception as e:
                    if os.path.exists(temp_file):
                        os.remove(temp_file)
                    # 异常时也关闭connector
                    if 'connector' in locals():
                        await connector.close()
                    if retry == self.config.retry_times - 1:
                        logger.error(f"分片{ts_idx}下载失败：{str(e)[:80]}")
                        return False
                    await asyncio.sleep(1 * (retry + 1))
        return False

    async def _batch_download(self, ts_list: List[Tuple[int, str]], proxies: Optional[str] = None):
        """异步分批次下载（核心极速逻辑）"""
        # 初始化并发控制
        self.semaphore = asyncio.Semaphore(self.config.max_concurrent)
        # 速率限制：每秒允许rate_limit MB（1MB=1024*1024字节）
        if self.config.enable_rate_limit:
            self.rate_limiter = asyncio.Semaphore(int(self.config.rate_limit))

        total_ts = len(ts_list)
        total_batches = (total_ts + self.config.batch_size - 1) // self.config.batch_size
        total_success = 0

        logger.info(
            f"异步下载开始：共{total_batches}批，每批{self.config.batch_size}分片，并发{self.config.max_concurrent}")

        for batch_idx in range(total_batches):
            start = batch_idx * self.config.batch_size
            end = min((batch_idx + 1) * self.config.batch_size, total_ts)
            batch_ts = ts_list[start:end]

            # 过滤已下载分片
            batch_ts = [ts for ts in batch_ts if ts[0] not in self.downloaded_ts]
            if not batch_ts:
                logger.info(f"第{batch_idx + 1}批：无需要下载的分片")
                continue

            # 异步批量执行
            tasks = [self._download_single_ts(ts, proxies) for ts in batch_ts]
            results = await asyncio.gather(*tasks)
            batch_success = sum(1 for res in results if res)
            total_success += batch_success

            logger.info(f"第{batch_idx + 1}/{total_batches}批完成：成功{batch_success}/{len(batch_ts)}个分片")

            # 批次间暂停（抗风控）
            if batch_idx < total_batches - 1:
                logger.info(f"批次间隔，暂停{self.config.batch_sleep}秒...")
                await asyncio.sleep(self.config.batch_sleep)

        logger.info(f"异步下载完成：总计成功{total_success}/{total_ts}个分片")
        return total_success

    async def _merge_ts(self, video_title: str) -> str:
        """异步合并TS分片（高效IO）- 合并后的文件保存到prohub文件夹"""
        if not self.temp_dir or not os.path.exists(self.temp_dir):
            raise TSMergeError("临时目录不存在")

        sanitized_title = AsyncUtils.sanitize_filename(video_title, self.config.forbidden_chars)
        # 视频文件路径改为：prohub/视频标题.mp4
        video_path = os.path.abspath(os.path.join(TARGET_DIR, f"{sanitized_title}.mp4"))

        # 排序TS文件
        ts_files = sorted(
            [f for f in os.listdir(self.temp_dir) if f.startswith("ts_") and f.endswith(".ts")],
            key=lambda x: int(x.split("_")[1].split(".")[0])
        )

        if not ts_files:
            raise TSMergeError("无可用分片")

        logger.info(f"开始合并{len(ts_files)}个分片到：{video_path}")

        # 异步合并（大文件分块）
        async with aiofiles.open(video_path, "wb") as out_f:
            for ts_file in ts_files:
                ts_path = os.path.join(self.temp_dir, ts_file)
                if os.path.getsize(ts_path) == 0:
                    logger.warning(f"跳过空分片：{ts_file}")
                    continue

                async with aiofiles.open(ts_path, "rb") as in_f:
                    while chunk := await in_f.read(self.config.chunk_size):
                        await out_f.write(chunk)

        # 清理临时目录
        if not self.config.enable_breakpoint:
            shutil.rmtree(self.temp_dir, ignore_errors=True)

        # 校验文件
        file_size = AsyncUtils.get_file_size(video_path)
        if file_size == "0B":
            raise TSMergeError("合并后的文件为空")

        logger.info(f"合并完成：文件大小{file_size}")
        return video_path

    async def download(self, m3u8_url: str, video_title: str, proxies: Optional[str] = None) -> str:
        """
        核心异步下载方法
        :param m3u8_url: M3U8 URL
        :param video_title: 视频标题
        :param proxies: 代理地址（如socks5://127.0.0.1:2164）
        :return: 视频路径
        """
        start_time = time.time()
        logger.info(f"异步下载启动：{m3u8_url}，标题：{video_title}")

        try:
            # 初始化
            self._init_temp_dir(video_title)

            # 解析M3U8
            ts_list = await self._parse_m3u8(m3u8_url, proxies)

            # 批量下载
            await self._batch_download(ts_list, proxies)

            # 合并分片
            video_path = await self._merge_ts(video_title)

            # 统计耗时
            cost_time = round(time.time() - start_time, 2)
            logger.info(f"下载完成：耗时{cost_time}秒，路径：{video_path}")

            return video_path

        except Exception as e:
            logger.error(f"下载失败：{e}", exc_info=True)
            raise M3U8DownloadError(f"下载失败：{e}")


# ===================== 5. 交互层（修复start_time未定义） =====================
class AsyncCLI:
    def __init__(self):
        self.config = AsyncUtils.load_config()
        self.downloader = AsyncM3U8Downloader(self.config)
        self.start_time = 0  # 修复：初始化start_time属性

    def print_banner(self):
        banner = f"""
=============================================
            M3U8异步极速下载工具（企业版）
---------------------------------------------
配置：异步并发{self.config.max_concurrent} | 每批{self.config.batch_size}分片
      断点续传：{"开启" if self.config.enable_breakpoint else "关闭"}
      速率限制：{"开启" if self.config.enable_rate_limit else "关闭"}({self.config.rate_limit}MB/s)
      存储目录：{TARGET_DIR}
=============================================
        """
        print(banner)

    def get_user_input(self) -> Tuple[str, str, Optional[str]]:
        # 1. M3U8 URL
        while True:
            m3u8_url = input("\n请输入M3U8完整URL：").strip()
            if AsyncUtils.is_valid_url(m3u8_url):
                break
            print("❌ URL格式非法！请输入带http/https的完整URL")

        # 2. 视频标题
        while True:
            video_title = input("请输入视频文件名（无需加.mp4）：").strip()
            if video_title and not any(c in video_title for c in self.config.forbidden_chars):
                break
            print(f"❌ 文件名非法！不能包含{''.join(self.config.forbidden_chars)}等字符")

        # 3. 代理配置
        use_proxy = input("\n是否使用代理？(y/n，默认n)：").strip().lower()
        proxies = None
        if use_proxy == "y":
            proxy_addr = input("请输入代理地址（如socks5://127.0.0.1:2164）：").strip()
            if proxy_addr and "://" in proxy_addr:
                proxies = proxy_addr
                print(f"✅ 已配置代理：{proxy_addr}")
            else:
                print("⚠️  代理地址格式错误，将不使用代理")

        return m3u8_url, video_title, proxies

    def run(self):
        self.print_banner()

        try:
            m3u8_url, video_title, proxies = self.get_user_input()
            self.start_time = time.time()  # 记录启动时间

            # 适配Windows异步事件循环
            if sys.platform == "win32":
                asyncio.set_event_loop_policy(asyncio.WindowsSelectorEventLoopPolicy())

            # 运行异步下载
            video_path = asyncio.run(self.downloader.download(m3u8_url, video_title, proxies))

            # 输出结果
            total_cost = round(time.time() - self.start_time, 2)
            print("\n" + "=" * 50)
            print("🎉 异步下载完成！（极速版）".center(50))
            print(f"📁 文件名：{os.path.basename(video_path)}")
            print(f"📍 存储路径：{video_path}")
            print(f"📊 文件大小：{AsyncUtils.get_file_size(video_path)}")
            print(f"⏱️  总耗时：{total_cost}秒")
            print(f"💡 若视频无法播放，执行：ffmpeg -i {video_path} -c copy {os.path.join(TARGET_DIR, f'{video_title}_fixed.mp4')}")
            print("=" * 50)

        except M3U8DownloadError as e:
            print(f"\n❌ 下载失败：{e}")
            sys.exit(1)
        except KeyboardInterrupt:
            print("\n⚠️  用户中断操作")
            sys.exit(0)


# ===================== 6. 入口函数 =====================
def main():
    # 检查依赖
    try:
        import aiohttp
        import aiofiles
    except ImportError:
        print("❌ 缺少依赖！请先执行：pip install aiohttp aiofiles")
        sys.exit(1)

    cli = AsyncCLI()
    cli.run()


if __name__ == "__main__":
    main()