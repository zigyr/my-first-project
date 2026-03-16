"""
python ./python/脚本/ctf/pro_sub_md5.py abc123
-> 启动 16 个进程，查找MD5[0:6] = abc123 的字符串...
-> 找到匹配字符串: l6zfd2wieh6Zb3wdRGCt
-> 验证MD5: abc1234142a4c1b0e16e8dbfae241c70
-> 截断部分: abc123
"""
from __future__ import annotations
import sys
import random
import hashlib
import multiprocessing
from typing import List, Optional, Any

# 定义字符集（Python3 中 string.letters 已废弃，改用 string.ascii_letters）
CHARS = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'

def cmp_md5(
    substr: str,
    stop_event: Any,
    str_len: int,
    start: int = 0,
    size: int = 20,
    result_queue: Any = None
) -> None:
    """
    暴力查找满足MD5截断条件的随机字符串
    :param substr: 目标MD5子串
    :param stop_event: 进程停止信号
    :param str_len: 匹配的子串长度
    :param start: MD5截断起始位置
    :param size: 随机字符串长度
    :param result_queue: 存储结果的队列
    """
    random.seed()  # 每个进程初始化独立随机种子，避免重复
    while not stop_event.is_set():
        # 生成随机字符串（Python3 优化生成方式）
        rnds = ''.join(random.choice(CHARS) for _ in range(size))
        # 计算MD5（Python3 需指定编码，避免字节/字符串混淆）
        md5_hash = hashlib.md5(rnds.encode('utf-8')).hexdigest()
        # 校验截断后的MD5子串
        if md5_hash[start:start+str_len] == substr:
            if result_queue:
                result_queue.put(rnds)
            stop_event.set()  # 通知所有进程停止
            return

def main() -> None:
    # 参数校验（增强鲁棒性）
    if len(sys.argv) < 2:
        print("使用方法: python md5_trunc.py <目标子串> [起始位置(默认0)]")
        sys.exit(1)
    
    substr = sys.argv[1].strip()
    start_pos = int(sys.argv[2]) if len(sys.argv) >= 3 else 0
    # 三元表达式
    # 变量 = 表达式 1 if 条件 else 表达式 2
    str_len = len(substr)
    
    # 校验起始位置合法性
    if start_pos + str_len > 32:
        print("错误：MD5哈希仅32位，起始位置+子串长度不能超过32")
        sys.exit(1)
    
    # 进程管理（优化多进程创建逻辑）
    cpu_count = multiprocessing.cpu_count()
    stop_event = multiprocessing.Event() # 多进程版本的 DFS flag
    result_queue = multiprocessing.Queue() # 多进程版本的 队列
    
    # 创建进程池（避免进程数过多，限制为CPU核心数的1.5倍）
    process_num = min(cpu_count * 2, 16)  # 最多16个进程，避免资源耗尽
    processes: List[multiprocessing.Process] = []
    # processes (: List[multiprocessing.Process]) = []    
    print(f"启动 {process_num} 个进程，查找MD`5[{start_pos}:{start_pos+str_len}] = {substr} 的字符串...")
    
    for _ in range(process_num):
        p = multiprocessing.Process(
            target=cmp_md5,
            args=(substr, stop_event, str_len, start_pos, 20, result_queue)
        )
        processes.append(p)
        p.start()
    
    # 等待进程结束
    for p in processes:
        p.join(timeout=300)  # 设置5分钟超时，避免无限等待
        # 子进程 “主动” 退出循环，正常结束
        if p.is_alive():
            p.terminate()  # 超时终止进程
        # 操作系统 “强制” 杀死子进程，被动结束
    
    # 输出结果
    if not result_queue.empty():
        result = result_queue.get()
        print(f"找到匹配字符串: {result}")
        # 验证结果（双重确认）
        verify_hash = hashlib.md5(result.encode('utf-8')).hexdigest()
        print(f"验证MD5: {verify_hash}")
        print(f"截断部分: {verify_hash[start_pos:start_pos+str_len]}")
    else:
        print("超时未找到匹配字符串")

if __name__ == '__main__':
    # Windows下多进程兼容（强制启动主进程保护）
    multiprocessing.freeze_support()
    main()