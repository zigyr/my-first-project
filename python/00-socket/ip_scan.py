import socket
import threading
from concurrent.futures import ThreadPoolExecutor

# 配置
BASE_DOMAIN = "pvp7391.bugku.cn"
YOUR_X = 109                    # 你自己的X值
START_X = 1
END_X = 254
THREAD_NUM = 50                # 线程数

def check_host(x):
    """检查某个X对应的域名是否存在"""
    if x == YOUR_X:
        return
    
    domain = f"192-168-1-{x}.{BASE_DOMAIN}"
    
    try:
        # 尝试解析域名
        ip = socket.gethostbyname(domain)
        print(f"[存活] {domain} -> {ip}")
        return domain
    except socket.gaierror:
        # 解析失败，该IP不存在
        pass
    except Exception as e:
        print(f"[错误] {domain}: {e}")

def main():
    print(f"[*] 开始扫描选手IP: {BASE_DOMAIN}")
    print(f"[*] 扫描范围: 192-168-1-1 到 192-168-1-254")
    print(f"[*] 跳过自己: 192-168-1-{YOUR_X}")
    print("-" * 60)
    
    found = []
    with ThreadPoolExecutor(max_workers=THREAD_NUM) as executor:
        results = executor.map(check_host, range(START_X, END_X + 1))
        for r in results:
            if r:
                found.append(r)
    
    print("-" * 60)
    print(f"[完成] 共找到 {len(found)} 个其他选手IP")
    for f in found:
        print(f"  {f}")

if __name__ == "__main__":
    main()