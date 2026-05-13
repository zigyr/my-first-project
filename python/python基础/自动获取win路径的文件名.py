import os

path = r"C:\Users\zigyr\Desktop\zigyr.github.io\_posts\文件上传\2026-04-28-1_基础切入.md"

# 含后缀
print(os.path.basename(path))

# 不含后缀
print(path.strip('\\').split('\\')[-1].split('.')[0])

# 父文件夹
print(os.path.dirname(path))