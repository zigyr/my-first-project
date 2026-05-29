plain = "system"

# 1. 字符串 → 数字列表（只这里需要 encode）
nums = [ord(c) for c in plain]

# 2. 按位取反
not_nums = [~x & 0xFF for x in nums]

# 3. 数字 → %xx 直接转！根本不用 bytes！！
result = ''.join(f'%{x:02x}' for x in not_nums)

print(result)  # %9e%8c%8c%9a%8d%8b