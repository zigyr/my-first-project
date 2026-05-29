import socket

# 要扫描的目标 IP
target = "127.0.0.1"

# 常见端口
ports = [22, 80, 443, 3306, 8080]

print(f"开始扫描 {target} ...")

for port in ports:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 超时时间
    s.settimeout(1)

    result = s.connect_ex((target, port))

    if result == 0:
        print(f"端口 {port} 开放")
    else:
        print(f"端口 {port} 关闭")

    s.close()