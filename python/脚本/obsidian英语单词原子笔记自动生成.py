"""
这是一个用于将 Obsidian 英语生词笔记中的内容，
自动拆分成极简原子笔记的 Python 脚本。
每个原子笔记只包含一个单词/短语及其翻译，并且文件名直接使用单词/短语（空格替换为短横线）.md
使用前请确保：
    修改 VAULT_PATH 和 INBOX_FILE 变量为你的实际路径
    尤其是 INBOX_FILE 中的参数，确保它指向正确的Inbox中的文件
"""
import os
import sys

def init_config():
    """初始化配置参数"""
    # 根文件夹路径（所有原子笔记都会存到这里）
    VAULT_PATH = r"E:\code-memory"
    # 代办1.md的路径
    INBOX_FILE = os.path.join(VAULT_PATH, "英语生词/00Inbox/代办1.md")
    
    return VAULT_PATH, INBOX_FILE

def get_note_template():
    """获取极简版笔记模板"""
    # 仅保留 单词/短语-翻译 的核心内容
    return "{english} - {chinese}"

def process_inbox_file(vault_path, inbox_file):
    """处理收件箱文件，拆分生成极简原子笔记"""
    # 检查文件是否存在
    if not os.path.exists(inbox_file):
        print(f"❌ 错误：文件不存在 - {inbox_file}")
        sys.exit(1)
    
    # 读取文件内容，过滤空行和标题行
    with open(inbox_file, 'r', encoding='utf-8') as f:
        lines = [line.strip() for line in f if line.strip()]
    
    if not lines:
        print("⚠️ 提示：收件箱文件为空，没有需要处理的生词")
        return
    
    note_template = get_note_template()
    created_count = 0
    
    # 逐行处理生词
    for line_num, line in enumerate(lines, 1):
        # 按 " - " 分割英文和中文
        if " - " not in line:
            print(f"⚠️ 第{line_num}行格式错误（需包含“英文 - 中文”）：{line}")
            continue
        
        english_part, chinese_part = line.split(" - ", 1)
        english = english_part.strip()
        chinese = chinese_part.strip()
        
        # 文件名直接用 单词/短语.md（处理空格为短横线，避免路径问题）
        safe_filename = f"{english.replace(' ', '-')}.md"
        file_path = os.path.join(vault_path, safe_filename)
        
        try:
            # 填充极简模板
            note_content = note_template.format(
                english=english,
                chinese=chinese
            )
            
            # 写入文件
            with open(file_path, 'w', encoding='utf-8') as note_file:
                note_file.write(note_content)
            
            created_count += 1
            print(f"✅ 已创建：{file_path}")
        
        except Exception as e:
            print(f"❌ 第{line_num}行处理失败：{line} | 错误：{str(e)}")
    
    print(f"\n🎉 处理完成！共创建 {created_count} 个原子笔记（总计 {len(lines)} 行数据）")

def main():
    """主函数"""
    print("===== Obsidian 英语生词拆分工具（终极极简版） =====")
    vault_path, inbox_file = init_config()
    process_inbox_file(vault_path, inbox_file)

if __name__ == "__main__":
    main()