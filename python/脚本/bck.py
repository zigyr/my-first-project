"""
feat: 完成 Obsidian 英语单词原子笔记自动生成脚本

核心功能:
- 智能分类: 根据AI补充信息自动归类单词至通用技术/Linux系统/Web安全等文件夹
- 原子笔记: 按模板自动生成仅含单词、翻译和来源的原子笔记
- MOC维护: 自动更新对应分类的MOC文件，并内置去重检测
- 日志维护: 完整记录运行过程，支持终端输出与文件持久化

使用说明:
- 配置init_config函数中的路径和分类信息
- 执行后重启 Obsidian 以刷新缓存索引
"""
import os
import sys
import shutil
import logging

def setup_logging():
    """设置日志记录"""
    logging.basicConfig(
        level=logging.INFO,
        format='%(asctime)s - %(levelname)s - %(message)s',
        handlers=[
            # 输出到日志文件，追加模式，utf-8编码
            logging.FileHandler('obsidian_note_run.log',encoding='utf-8',mode='a'),
            # 同时输出到控制台
            logging.StreamHandler(sys.stdout)
        ]
    )

def init_config():
    """初始化配置参数"""
    # 两个Inbox文件夹路径（所有原子笔记都会存到这里）
    ROU_SOURCE_PATH = r"E:\code-memory\英语生词\00Inbox-待处理"
    ROU_TARGET_PATH = r"E:\code-memory\英语生词\99Inbox-已归档"
    # 分类文件夹路径（可选，根据需要调整）
    category_paths={
        "A": r"E:\code-memory\英语生词\通用技术",
        "B": r"E:\code-memory\英语生词\Linux系统",
        "C": r"E:\code-memory\英语生词\Web安全"
    } 
    # 分类moc路径（可选，根据需要调整）
    moc_paths = {
        "A": r"E:\code-memory\英语生词\--MOC\通用技术-MOC.md",
        "B": r"E:\code-memory\英语生词\--MOC\Linux系统-MOC.md",
        "C": r"E:\code-memory\英语生词\--MOC\Web安全-MOC.md"
    }
    # 代办的路径
    file_name = input("请输入代办文件名（不带扩展名，例如：代办1）：").strip()
    DEL_SOURCE_PATH = os.path.join(ROU_SOURCE_PATH, f"{file_name}.md")
    DEL_TARGET_PATH = os.path.join(ROU_TARGET_PATH, f"{file_name}.md")

    return {
        "category_paths": category_paths,
        "moc_paths": moc_paths,
        "DEL_SOURCE_PATH": DEL_SOURCE_PATH,
        "DEL_TARGET_PATH": DEL_TARGET_PATH
    }

def get_note_template():
    """获取极简版笔记模板"""
    # 仅保留 单词/短语-翻译 的核心内容
    template =  """
# `{english}`-{chinese}
# 来源`：{resource}`
    """
    return template.strip()

def process_inbox_file(config):
    """处理收件箱文件，拆分生成极简原子笔记"""
    category_paths = config["category_paths"]
    moc_paths = config["moc_paths"]
    inbox_file = config["DEL_SOURCE_PATH"]

    # 检查文件是否存在
    if not os.path.exists(inbox_file):
        logging.error(f"文件不存在 - {inbox_file}")
        sys.exit(1)
    
    #获得文件来源
    resource_tmp = os.path.basename(inbox_file)
    resource_without_ext = os.path.splitext(resource_tmp)[0]
    resource = resource_without_ext.replace('：',':').split(':')[-1].strip()

    # 读取文件内容，过滤空行和标题行
    with open(inbox_file, 'r', encoding='utf-8') as f:
        lines = [line.strip() for line in f if line.strip()]
    
    if not lines:
        logging.warning("收件箱文件为空，没有需要处理的生词")
        return
    
    # 配置极简模板
    note_template = get_note_template()
    creat_note = 0
    update_moc = 0
    # 逐行处理生词
    for line_num, line in enumerate(lines, 1):
        # 通过配置maxsplit参数优雅分割英文和中文和来源
        if " - " not in line:
            logging.warning(f"第{line_num}个单词/短语错误（需包含“英文 - 中文”）：{line}")
            continue
        
        parts = line.split(" - ",maxsplit = 2)
        english = parts[0].strip()
        chinese = parts[1].strip()
        index = parts[2].strip()
        
        # 检查 index 是否在 category_paths 中
        if index not in category_paths:
            logging.warning(f"第{line_num}个单词/短语的索引错误（未在 category_paths 中找到）：{index}")
            continue

        # 文件名直接用 单词/短语.md（处理空格为短横线，避免路径问题）
        save_filename = f"{english.replace(' ', '-')}.md"
        # 根据index实现的自动文件路径分类
        file_path = os.path.join(category_paths[index], save_filename)

        try:
            # 填充极简模板
            note_content = note_template.format(
                english=english,
                chinese=chinese,
                resource = resource
            )
            
            # 写入文件
            with open(file_path, 'w', encoding='utf-8') as note_file:
                note_file.write(note_content)
            
            creat_note += 1
            logging.info(f"✅ 已创建：{file_path}")
        
        except Exception as e:
            logging.error(f"❌ 第{line_num}行处理失败：{line} | 错误：{str(e)}")

        try :
            # 同时更新对应分类的MOC文件
            moc_file = moc_paths[index]
            link_to_add = f"[[{english.replace(' ', '-')}.md]]"

            with open(moc_file, 'r', encoding='utf-8') as moc_f:
                moc_content = moc_f.read()

            if link_to_add in moc_content:
                logging.warning(f"⚠️ 单词/短语{english}的 MOC 已存在链接，跳过更新词条：{line}")
                pass
            else:
                with open(moc_file,'a',encoding='utf-8') as moc_f:
                    moc_f.write(f"- {link_to_add}\n")
                logging.info(f"✅ 已更新 MOC：{moc_file}") 
                update_moc += 1

        except Exception as e:
            logging.error(f"❌ 第{line_num}个单词/短语的 MOC 更新失败：{line} | 错误：{str(e)}")
    
    logging.info(f"\n🎉 处理完成！共创建 {creat_note} 个原子笔记（总计 {len(lines)} 行数据）")
    logging.info(f"✅ 同时更新 {update_moc} 个 MOC 文件")

    # 处理完成后将原文件移动到已归档文件夹
    source_file = config["DEL_SOURCE_PATH"]
    target_file = config["DEL_TARGET_PATH"]
    
    try:
        shutil.move(source_file, target_file)
        logging.info(f"✅ 已将原文件移动到已归档：{target_file}")
    except Exception as e:
        logging.error(f"❌ 原文件移动失败：{source_file} -> {target_file} | 错误：{str(e)}")

def main():
    """主函数"""
    setup_logging()
    logging.info("===== Obsidian 英语生词拆分工具（终极极简版） =====")
    config = init_config()
    process_inbox_file(config)

if __name__ == "__main__":
    main()