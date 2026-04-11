import os

path = r'F:\Compilers\python2'

def print_tree(root_dir, prefix=""):
    # 列出当前目录下的所有内容（文件夹 + 文件）
    items = list(os.scandir(root_dir))
    # 先排文件夹，再排文件
    items.sort(key=lambda x: (not x.is_dir(), x.name))

    # 遍历每一项
    for i, item in enumerate(items):
        # 判断是不是最后一个
        is_last = (i == len(items) - 1)

        # 打印当前项
        # 三元表达式：结果A if 条件 else 结果B
        if item.is_dir():
            # 文件夹
            print(f"{prefix}{ '+- ' if is_last else '+  ' }📁 {item.name}")
            # 递归进入子文件夹
            new_prefix = prefix + ( "    " if is_last else "|   " )
            print_tree(item.path, new_prefix)
        else:
            # 文件
            print(f"{prefix}{ '+- ' if is_last else '+  ' }📄 {item.name}")


print(f"📁 {os.path.basename(path)}")
print_tree(path)

"""
`items.sort(key=lambda x: (not x.is_dir(), x.name))`
原内容	     第一项 not x.is_dir()	第二项 x.name	最终排序标签
📁 文件夹 A	 False	                "文件夹 A"	    (False, "文件夹A")
📁 文件夹 B	 False	                "文件夹 B"	    (False, "文件夹B")
📄 文件 A	 True	                "文件 A"	    (True, "文件A")
📄 文件 B	 True	                "文件 B"	    (True, "文件B")
"""


# 关于prefix的递归
"""
`new_prefix = prefix + ("    " if is_last else "|   ")`
📁 test
+  📁 1
|   +- 📄 1.txt
+- 📁 2
    +- 📄 2.txt
"""