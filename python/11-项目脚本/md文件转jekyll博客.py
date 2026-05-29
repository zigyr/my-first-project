"""
目前功能:
1. 自动添加front_matter内容
2. 自动改正文件名
3. 递归读取根目录（_posts），进行文件修改
"""

"""待优化
代办：
"""
import os
from datetime import datetime

front_matter = """---
title: SSTI | {title}
date: {time}
categories: [笔记]
tags: [SSTI]
mermaid: True
---
"""

# 获取文件名
# [0]无后缀
# [1]有后缀
def get_title(path):
    return[
        path.strip('\\').split('\\')[-1].split('.')[0],
        os.path.basename(path)
    ]

# 添加front_matter
def add_front_matter(md_path):

    title = get_title(md_path)[0]
    time_str = datetime.now().strftime("%Y-%m-%d %H:%M:%S +0800")

    front_matter_content = front_matter.format(title=title, time=time_str)

    with open(md_path, "r", encoding='utf-8') as f:
        ori_content = f.read()

    cur_content = front_matter_content + '\n' + "{%raw%}" + '\n' + ori_content + '\n' + "{%endraw%}"

    with open(md_path, "w", encoding='utf-8') as f:
        f.write(cur_content)

# 修改文件名
def change_title(md_path):

    time_str = datetime.now().strftime("%Y-%m-%d")

    ori_filename = get_title(md_path)[1]
    goa_filename = time_str + '-' + ori_filename

    dirname = os.path.dirname(md_path)

    old_path = os.path.join(dirname, ori_filename)
    new_path = os.path.join(dirname, goa_filename)

    os.rename(old_path, new_path)

# 依据文件名判断是否需要改良
def check(filename):
    return filename[:4] == "2026"

# 最终针对单个文件的改良
def refine(file_path):

    # front_matter
    add_front_matter(file_path)

    # 文件名
    change_title(file_path)
        
# 递归获取根目录下的所有文件名
def get_all_files(root_path, all_files):

    items = list(os.scandir(root_path))  # 注意list强转

    items.sort(key=lambda x:(not x.is_dir(), x.name))

    for item in items:

        if item.is_dir():
            
            get_all_files(item.path, all_files)

        else:

            if not check(item.path.strip('\\').split('\\')[-1]):

                all_files.append(item.path)


def final(blog_folder):

    all_files = []
    cou = 0

    get_all_files(blog_folder, all_files)

    
    for file in all_files:
        cou += 1
        refine(file)
        print(f"[+] 已成功改良笔记 {file.split("_posts")[-1]}")

    print(f"\n[+] 本次共改良笔记 {cou} 篇")



if __name__ == "__main__":

    blog_folder = r"C:\Users\zigyr\Desktop\zigyr.github.io\_posts"

    final(blog_folder)