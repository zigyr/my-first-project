import string

data = open(r'F:\code_practice\code\python\ctf\NSSCTF\[LitCTF 2025]消失的文字\hidden-word.txt',encoding='utf-8').read()

print(bytes
    ([
    ord(i) % 256 + 16 
    for i in data  
    if i not in string.printable  # 只保留：不是正常可打印字符的东西
    ])
)  
"""
扔掉所有正常英文 Litctf~ ! This is a contest...
只留下乱码：󠄼 󠅙 󠅤 󠄳 ...
把这些乱码解码
输出 真正藏的信息（大概率是 flag）
"""