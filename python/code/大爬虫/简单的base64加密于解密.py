import base64

print("本项目可进行简单的base64加密解密！！！")
print("--------------------------------")
print("请输入数字来进行选择(1:加密，2:解密),同时传入进行加密或解密的字符串")
# a,or_data = input().split()
a,or_data=input().strip().split(maxsplit=1)
# a = input("请输入数字来进行选择(1:加密，2:解密)")
# a=int(input("请输入数字来进行选择(1:加密，2:解密)"))
if a == "1":
# if a==1:
#     or_data = input("请输入你要加密的数据：")
    data = f"{or_data}"
    o_data = data.encode('utf-8')
    res = base64.b64encode(o_data).decode('utf-8')
    print(res)
if a == "2":
# if a==2:
    # or_data = input("请输入你要解密的数据：")
    or_data = f"{or_data}"
    or_data += ("=" * (4 - len(or_data) % 4))
    o_data = or_data.encode("utf-8")
    res = base64.b64decode(o_data).decode("utf-8")
    print(res)
