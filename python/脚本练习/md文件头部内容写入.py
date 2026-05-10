"""待优化
1. 根据原有文件的md文件名，进行前缀转换
2. 根据原有文件的md文件名，进行title
3. 根据目前的时间，进行date的自动补充
4. 自动处理目录下的批量文件（特征分析？：未进行文件名的有效命名）
"""

def add_text_to_md_head(md_path, head_str):
    # 读取源文件全部内容
    with open(md_path, 'r', encoding='utf-8') as f:
        old_content = f.read()

    # 头部新字符串 + 原内容拼接
    new_content = head_str + "\n" + old_content

    # 覆盖写入源文件
    with open(md_path, 'w', encoding='utf-8') as f:
        f.write(new_content)

if __name__ == "__main__":
    md_file = r"C:\Users\zigyr\Desktop\zigyr.github.io\_posts"

    add_head_text = """---
title: 文件上传 | 图片马绕过
date: 2026-05-06 18:40:00 +0800
categories: [笔记]
tags: [文件上传]
---
"""

    add_text_to_md_head(md_file, add_head_text)