import os

def search_in_files(path, key):
    for root, dirs, files in os.walk(path):
        for file in files:
            file_path = os.path.join(root, file)
            try:
                with open (file_path, "r", encoding = 'utf-8') as f:
                    content = f.read()
                    if key in content:
                        print(f"在文件 {file_path} 中找到关键词 {key}")
            except Exception as e:
                pass

path = "C:\\Users\\zigyr\\desktop\\test"

search_in_files(path, "flag")


"""
📁 C:\\Users\\zigyr\\desktop\\test
+  📁 1
|   +  📁 aaa
|   |   +  📁 bbb
|   |   |   +- 📄 flag.txt
|   |   +- 📁 ccc
|   +- 📄 1.txt
+- 📁 2
    +  📁 ddd
    |   +  📁 eee
    |   |   +- 📁 flag
    |   |       +- 📄 111.txt
    |   +- 📁 qqq
    +- 📄 2.txt

在文件 C:\Users\zigyr\desktop\test\1\aaa\bbb\flag.txt 中找到关键词 flag
在文件 C:\Users\zigyr\desktop\test\2\2.txt 中找到关键词 flag
在文件 C:\Users\zigyr\desktop\test\2\ddd\eee\flag\111.txt 中找到关键词 flag
"""

