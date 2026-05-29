from langchain_community.document_loaders import TextLoader
from langchain_text_splitters import RecursiveCharacterTextSplitter


loader = TextLoader(
    file_path = "F:\\code_practice\\code\\python\\AI大模型RAG与智能体开发\\P3_LangChainRAG开发\\data\\stu.txt",
    encoding = "utf-8"
)

docs = loader.load()

splitter = RecursiveCharacterTextSplitter(
    chunk_size=600,        # 分段的最大字数
    chunk_overlap=80,      # 分段之间, 允许重叠字符数
    separators=[
        "\n\n",       # 1. 优先按大段落分割（最完整）
        "\n",         # 2. 按换行分割
        "。", "；",   # 3. 按中文句子
        "，", "？", "！",
        ".", ";", ",",
        " ", ""       # 兜底
    ],
    add_start_index=True,   # 记录位置，方便检索 print(chunk.metadata)
    length_function = len, # 统计字符的依据函数 
)

split_docs = splitter.split_documents(docs)

for i, chunk in enumerate(split_docs):
    print(f"===== 第 {i+1} 块 =====")
    print(chunk.page_content)   # 只打印纯文本内容
    # print(chunk)                #打印完整的 Document 对象
    print()