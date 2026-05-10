import base64

"""
语法几乎一样
加密
    res = base64.b64encode(or_data.encode('utf-8')).decode('utf-8')
解密
    res = base64.b64decode(or_data.encode("utf-8")).decode("utf-8")
"""

print("本项目可进行简单的base64加密解密！！！")
print("--------------------------------")
print("请输入数字来进行选择(1:加密，2:解密)，同时传入要处理的字符串")
print("示例：1 你好世界  或  2 SGVsbG8=")

# 读取输入，只分割一次，保证后面的内容完整
try:
    a, or_data = input().strip().split(maxsplit=1)
except ValueError:
    print("输入格式错误！请按照【数字 内容】格式输入，例如：1 hello")
    exit()

# 加密
if a == "1":
    data_bytes = or_data.encode('utf-8')
    res = base64.b64encode(data_bytes).decode('utf-8')
    print("加密结果：", res)

# 解密
elif a == "2":
    try:
        # 自动补全等号（Base64 要求长度是4的倍数）
        or_data += "=" * ((4 - len(or_data) % 4) % 4)
        data_bytes = or_data.encode("utf-8")
        res = base64.b64decode(data_bytes).decode("utf-8")
        print("解密结果：", res)
    except:
        print("解密失败！输入的不是有效的Base64格式")