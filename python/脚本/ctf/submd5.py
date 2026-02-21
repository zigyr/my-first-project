import multiprocessing
import hashlib
import random
import string
import sys

# 定义字符集：大小写字母 + 数字
CHARS = string.ascii_letters + string.digits

def cmp_md5(substr, stop_event, str_len, start=0, size=20):
    global CHARS
    while not stop_event.is_set():
        # 生成随机字符串
        rnds = ''.join(random.choice(CHARS) for _ in range(size))
        # 计算 MD5
        md5_hash = hashlib.md5(rnds.encode('utf-8')).hexdigest()
        # 检查最后6位是否匹配
        if md5_hash[-str_len:] == substr:
            print(f"找到匹配: {rnds} -> MD5: {md5_hash}")
            stop_event.set()

if __name__ == '__main__':
    # 目标MD5后缀
    target_suffix = "8b184b"
    str_len = len(target_suffix)
    
    # 使用CPU核心数创建多进程
    cpus = multiprocessing.cpu_count()
    stop_event = multiprocessing.Event()
    
    processes = [multiprocessing.Process(target=cmp_md5, args=(target_suffix, stop_event, str_len))
                 for _ in range(cpus)]
    
    for p in processes:
        p.start()
    
    for p in processes:
        p.join()