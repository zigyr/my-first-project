from tqdm import tqdm
import time

# 模拟你的 ts 分片列表
ts_list = [f"ts_{i}" for i in range(200)]  # 200个分片

# 👇 这一行就是 pip 同款进度条
for ts in tqdm(ts_list, desc="下载中", unit="片"):
    # 这里写你的下载代码
    time.sleep(0.01)