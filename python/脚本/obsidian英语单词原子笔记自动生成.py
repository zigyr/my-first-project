#!/usr/bin/env python3
# -*- coding: utf-8 -*-
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

升级：
- json文本处理
- pyperclip.paste自动获取剪贴板内容

代办:
- 企业级程序思维
"""

import os
import sys
import shutil
import logging
import pyperclip
import json
from openai import OpenAI

# ======================== 常量定义 ========================
LOG_FILE = "obsidian_note_run.log"
DEEPSEEK_BASE_URL = "https://api.deepseek.com/v1"
DEEPSEEK_MODEL = "deepseek-chat"

# ======================== 日志配置 ========================
def setup_logging():
    """
    设置日志记录配置
    - 日志级别: INFO
    - 输出目标: 日志文件(obsidian_note_run.log) + 控制台
    - 编码格式: UTF-8
    - 日志格式: 时间 - 级别 - 消息
    """
    # 定义日志格式
    log_format = logging.Formatter("%(asctime)s - %(levelname)s - %(message)s")
    
    # 配置根日志器
    logger = logging.getLogger()
    logger.setLevel(logging.INFO)
    
    # 清除已存在的处理器（避免重复输出）
    logger.handlers.clear()

    # 1. 文件处理器 - 追加模式，UTF-8编码
    file_handler = logging.FileHandler(LOG_FILE, encoding="utf-8", mode="a")
    file_handler.setFormatter(log_format)
    logger.addHandler(file_handler)

    # 2. 控制台处理器
    console_handler = logging.StreamHandler(sys.stdout)
    console_handler.setFormatter(log_format)
    logger.addHandler(console_handler)

# ======================== 配置初始化 ========================
def init_config():
    """
    初始化脚本核心配置参数
    返回: 包含所有配置的字典
    """
    # 基础路径配置
    inbox_source_path = r"E:\code-memory\英语生词\00Inbox-待处理"
    inbox_target_path = r"E:\code-memory\英语生词\99Inbox-已归档"

    # 分类文件夹路径映射 (A/B/C 对应不同分类)
    category_paths = {
        "A": r"E:\code-memory\英语生词\通用技术",
        "B": r"E:\code-memory\英语生词\Linux系统",
        "C": r"E:\code-memory\英语生词\Web安全"
    }

    # MOC文件路径映射
    moc_paths = {
        "A": r"E:\code-memory\英语生词\--MOC\通用技术-MOC.md",
        "B": r"E:\code-memory\英语生词\--MOC\Linux系统-MOC.md",
        "C": r"E:\code-memory\英语生词\--MOC\Web安全-MOC.md"
    }

    # 从剪贴板获取文件名（去除首尾空白）
    file_name = pyperclip.paste().strip()
    
    # 待处理/已归档文件完整路径
    del_source_path = os.path.join(inbox_source_path, f"{file_name}.md")
    del_target_path = os.path.join(inbox_target_path, f"{file_name}.md")

    # AI 提示词模板（JSON格式输出要求）
    format_prompt = (
        "处理英文术语：1转原形；2修正拼写；3计算机中译；4按A通用/B Linux/C Web安全分类；5保留短语。"
        "输出一行JSON：[{\"e\":\"英文\",\"c\":\"中文\",\"t\":\"类别\"}]，无多余内容"
    )

    # API密钥（从环境变量获取）
    api_key = os.getenv("DEEPSEEK_API_KEY")

    return {
        "category_paths": category_paths,
        "moc_paths": moc_paths,
        "del_source_path": del_source_path,
        "del_target_path": del_target_path,
        "file_name": file_name,
        "format_prompt": format_prompt,
        "api_key": api_key
    }

# ======================== AI 接口调用 ========================
def call_ai_api(config):
    """
    调用DeepSeek AI接口处理单词/短语
    参数:
        config: 配置字典
    返回:
        AI返回的JSON格式字符串
    """
    # 读取待处理文件内容
    with open(config["del_source_path"], "r", encoding="utf-8") as f:
        file_content = f.read().strip()

    # 初始化OpenAI客户端（适配DeepSeek）
    client = OpenAI(
        api_key=config["api_key"],
        base_url=DEEPSEEK_BASE_URL
    )

    # 调用AI接口
    response = client.chat.completions.create(
        model=DEEPSEEK_MODEL,
        messages=[
            {"role": "system", "content": config["format_prompt"]},
            {"role": "user", "content": file_content}
        ]
    )
    
    return response.choices[0].message.content

# ======================== 文件操作 ========================
def move_source_file(config):
    """
    将待处理文件移动到已归档文件夹
    参数:
        config: 配置字典
    """
    source_file = config["del_source_path"]
    target_file = config["del_target_path"]
    
    try:
        shutil.move(source_file, target_file)
        logging.info(f"✅ 已将原文件移动到已归档：{target_file}")
    except Exception as e:
        logging.error(f"❌ 原文件移动失败：{source_file} -> {target_file} | 错误：{str(e)}")

def get_note_template():
    """
    获取极简版单词笔记模板
    模板包含: 单词/短语、中文翻译、来源
    """
    template = """# `{english}`-{chinese}
# 来源：{resource}"""
    return template.strip()

# ======================== 核心处理逻辑 ========================
def process_inbox_file(config, ai_response_data):
    """
    处理收件箱文件，拆分生成原子笔记并更新MOC
    参数:
        config: 配置字典
        ai_response_data: AI返回的JSON字符串
    """
    category_paths = config["category_paths"]
    moc_paths = config["moc_paths"]
    
    # 提取文件来源（从文件名中解析）
    resource = os.path.splitext(config["file_name"])[0].replace("：", ":").split(":")[-1].strip()
    
    # 获取笔记模板
    note_template = get_note_template()

    # 统计变量
    created_notes_count = 0
    updated_moc_count = 0

    # 解析AI返回的JSON数据
    word_list = json.loads(ai_response_data.strip())
    
    # 逐行处理每个单词/短语
    for line_num, word_info in enumerate(word_list, 1):
        english = word_info["e"].strip()
        chinese = word_info["c"].strip()
        category_code = word_info["t"].strip()

        # 检查分类编码是否有效
        if category_code not in category_paths:
            logging.warning(f"第{line_num}个单词/短语的索引错误（未在 category_paths 中找到）：{category_code}")
            continue

        # 生成文件名（空格替换为短横线，避免路径问题）
        note_filename = f"{english.replace(' ', '-')}.md"
        note_file_path = os.path.join(category_paths[category_code], note_filename)

        # 生成并写入原子笔记
        try:
            note_content = note_template.format(
                english=english,
                chinese=chinese,
                resource=resource
            )
            
            with open(note_file_path, "w", encoding="utf-8") as note_file:
                note_file.write(note_content)
            
            created_notes_count += 1
            logging.info(f"✅ 已创建原子笔记：{note_file_path}")
        
        except Exception as e:
            logging.error(f"❌ 第{line_num}行笔记创建失败：{word_info} | 错误：{str(e)}")

        # 更新对应分类的MOC文件（去重）
        try:
            moc_file_path = moc_paths[category_code]
            note_link = f"[[{english.replace(' ', '-')}.md]]"

            # 检查链接是否已存在
            with open(moc_file_path, "r", encoding="utf-8") as moc_file:
                moc_content = moc_file.read()

            if note_link in moc_content:
                logging.warning(f"⚠️ MOC已存在链接，跳过：{note_link}")
            else:
                with open(moc_file_path, "a", encoding="utf-8") as moc_file:
                    moc_file.write(f"- {note_link}\n")
                logging.info(f"✅ 已更新MOC文件：{moc_file_path}")
                updated_moc_count += 1

        except Exception as e:
            logging.error(f"❌ 第{line_num}行MOC更新失败：{word_info} | 错误：{str(e)}")
    
    # 输出处理统计结果
    logging.info("🎉 处理完成！")
    print("============================================================================================")
    logging.info(f"📝 共处理 {len(word_list)} 个单词/短语，成功创建 {created_notes_count} 个原子笔记")
    logging.info(f"📑 成功更新 {updated_moc_count} 个MOC文件")

# ======================== 主函数 ========================
def main():
    """脚本主入口"""
    # 初始化日志
    setup_logging()
    
    # 加载配置
    config = init_config()
    
    logging.info(f"""
                 ===== Obsidian 英语生词拆分工具（终极极简版）=====
                 功能：智能分类 + 原子笔记 + MOC维护 + 日志记录
                 -----------------------------------------------
                 正在处理文件：{config["file_name"]}
                 来源解析中...
                 """)

    # 调用AI接口处理数据
    ai_data = call_ai_api(config)
    
    # 处理文件并生成原子笔记
    process_inbox_file(config, ai_data)
    
    # 移动源文件到已归档
    move_source_file(config)

if __name__ == "__main__":
    main()