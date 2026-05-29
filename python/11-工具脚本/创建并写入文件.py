"""

"""
import os

def zero_write_file(file_path, content):
    dirname = os.path.dirname(file_path)
    if dirname and not os.path.exists(dirname):
        os.makedirs(dirname, exist_ok = True)
    
    with open(file_path, "w", encoding = 'utf-8') as f:
        f.write(content)

file_path = "C:\\Users\\zigyr\\Desktop\\test\\1\\ccccc"
zero_write_file(file_path, "hello, world")
print(f"内容成功插入进{file_path}")