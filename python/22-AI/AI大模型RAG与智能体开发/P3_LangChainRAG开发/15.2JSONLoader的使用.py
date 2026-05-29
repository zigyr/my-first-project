# JSONLoader以来jq库, 需要通过pip install jq安装
from langchain_community.document_loaders import JSONLoader

loader = JSONLoader(
    file_path = "F:\\code_practice\\code\\python\\AI大模型RAG与智能体开发\\P3_LangChainRAG开发\\data\\stu.json",
    jq_schema = ".",
    text_content = False,   # 告知JSONLoader 提取的内容不是字符串
    # 默认是 True, 非必填

    # file_path = "F:\\code_practice\\code\\python\\AI大模型RAG与智能体开发\\P3_LangChainRAG开发\\data\\stu_json_lines.json",
    # jq_schema = ".name",
    # json_lines = True,     # 告知JSONLoader 这是一个JSONLines文件（每一行都是一个独立的标准Json）
    # # 默认是False, 非必填
)

document = loader.load()
print(document)

"""
{
 "name": "\\u5468\\u6770\\u4f26", 
 "age": 11, 
 "hobby": ["\\u5531", "\\u8df3", "rap"], 
 "other": {
    "addr": "\\u6df1\\u5733", 
    "tel": "12332112321"
    }
}
"""