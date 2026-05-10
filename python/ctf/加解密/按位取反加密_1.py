# 目标：把 assert 加密成 URL 编码格式 %9e%8c%8c%9a%8d%8b

# 1. 原始字符串
plain = "assert"

# 2. 转成字节数组
data = plain.encode("latin-1")

# 3. 每个字节按位取反（和 PHP ~ 效果一样）
not_bytes = bytes([~b & 0xFF for b in data])

# 4. 转成 URL 编码（最终加密结果）
def byte_to_hex(c):
    return f"%{c:02x}"

encrypted = "".join([byte_to_hex(b) for b in not_bytes])

# 输出结果
print("加密结果：", encrypted)