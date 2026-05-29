import re

def clean_content(content):
    
    content = re.sub(r'```(.*?)```', r'\1', content, flags = re.DOTALL)

    clean_lines = []

    lines = content.split('\n')

    for line in lines:
            
        # 标题 #
        line = re.sub(r'^#{1,6}\s+', '', line, flags = re.MULTILINE)

        # 加粗 **
        line = re.sub(r'\*\*(.*?)\*\*', r'\1', line)


        # 行内代码 ``
        line = re.sub(r'`(.*?)`', r'\1', line)

        # 图片 ![alt](url)
        line = re.sub(r'!\[(.*?)\]\((.*?)\)', r'\1 : \2', line)

        # 链接 [文本](链接)
        line = re.sub(r'\[(.*?)\]\((.*?)\)', r'\1 : \2', line)

        # 无序列表 -*+
        line = re.sub(r'^[-*+]\s+', '', line, flags = re.MULTILINE)
        line = re.sub(r'^\s+[-*+]\s+', '', line, flags = re.MULTILINE)
        # 有序列表 1.
        line = re.sub(r'^\d+\.\s+', '', line, flags = re.MULTILINE)

        # 斜体 *
        line = re.sub(r'\*(.*?)\*', r'\1', line)

        if line.strip():
            clean_lines.append(line)

    return '\n'.join(clean_lines)

with open('input.md', 'r', encoding = 'utf-8') as f:
    content = f.read()

clean_content = clean_content(content)

with open('output.txt', 'w', encoding = 'utf-8') as f:
    f.write(clean_content)