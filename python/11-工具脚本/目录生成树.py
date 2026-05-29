import os

path = r'F:\md_txt\obsidianFILE\self_personity'

def print_tree(root_dir, prefix = ""):

    items = list(os.scandir(root_dir))

    items.sort(key=lambda x: ( not x.is_dir() , x.name))

    for i, item in enumerate(items):

        is_last = (i == len(items) - 1)

        if item.is_dir():

            print(f"{prefix}{"+- " if is_last else "+ "} [fold] {item.name}")

            new_prefix = prefix + ("   " if is_last else "|  ")

            print_tree(item.path, new_prefix)

        else:
            print(f"{prefix}{"+- " if is_last else "+  "}[file] {item.name}")


print(f"[+] {os.path.basename(path)}")
print_tree(path)

"""
关于
{'+- ' if is_last else '+  '}
('+- ' if is_last else '+  ')
{ } 大括号 = 只能用在 f-string 字符串里面
( ) 小括号 = 用在普通代码赋值、计算里面
"""

"""
`items.sort(key=lambda x: (not x.is_dir(), x.name))`
关于sort中结合key的排序原理：

原内容	     第一项 not x.is_dir()	第二项 x.name	最终排序标签
📁 文件夹 A	 False	                "文件夹 A"	    (False, "文件夹A")
📁 文件夹 B	 False	                "文件夹 B"	    (False, "文件夹B")
📄 文件 A	 True	                "文件 A"	    (True, "文件A")
📄 文件 B	 True	                "文件 B"	    (True, "文件B")

最终形成一个列表之类的东东, 且元素是一对键值构成的元组
而python比较元素(a, b)的规则是
先根据元组的键进行升序排序, 当多个元组的键相等时再根据元组的值进行升序排序
"""


# 关于prefix的递归
"""
`new_prefix = prefix + ("    " if is_last else "|   ")`
📁 test
+  📁 1
|   +  📁 aaa
|   |   +  📁 bbb
|   |   |   +- 📄 flag.txt
|   |   +- 📁 ccc
|   +  📄 1.txt
|   +- 📄 ccccc
+- 📁 2
    +  📁 ddd
    |   +  📁 eee
    |   |   +- 📁 flag
    |   |       +- 📄 111.txt
    |   +- 📁 qqq
    +- 📄 2.txt
"""