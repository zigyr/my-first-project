def encrypt(m,k):
    return ''.join([chr(ord(a)^k) for a in m])

num=int(input("1.加密，2.解密，请输入1或2进行选择"))
if num==1:
    m=input("请输入你要加密的内容：")
    k=int(input("请输入你的密钥："))
    print(f"{m}，加密后的内容为{encrypt(m,k)}，请注意保存密钥{k}")
else:
    m=input("请输入你要解密的内容：")
    k=int(input("请输入你保存的密钥："))
    print(f"{m}，解密后的内容为{encrypt(m,k)}")
