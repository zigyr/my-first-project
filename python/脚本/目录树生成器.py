import os

path = 'C:\\Users\\zige\\Desktop\\text'

# lines = os.listdir(path)
# for line in lines:
#     print(line)

# for root, dirs, files in os.walk(path):
#     # print(f"当前所在路径: {root}")
#     # print(f"这一层的子文件夹{dirs}")
#     # print(f"这一层的文件{files}")

#     for f in files:
#         print(f" -> 打印文件: {f}")
    
#     print("-" * 40)

def generate_tree(path):
    lines = os.listdir(path)
    for line in lines:
        line = os.path.join(path, line)
        if os.path.isfile(line):
            filename = os.path.basename(line)
            print(filename)
        elif os.path.isdir(line):
            print(f"进入目录{line}, 开始扫描")
            generate_tree(line)
            print("-" * 40)

generate_tree(path)