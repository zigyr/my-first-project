from langchain_community.document_loaders import CSVLoader

loader = CSVLoader(
    file_path = "F:\\code_practice\\code\\python\\AI大模型RAG与智能体开发\\P3_LangChainRAG开发\\data\\stu.csv",
    csv_args = {
        "delimiter": ",",       # 指定分隔符
        "quotechar": '"',       # 指定带有分隔符文本的引号包围是单引号还是双引号
        # 如果数据没有表头, 就不要下面的代码, 如果没有可以使用
        "fieldnames": ['name', 'age', 'gender', 'hobby'],
    },
    encoding = 'utf-8'
)


# # 批量加载 -》[Document, Document, ...]
# for document in loader.load():
#     print(type(document), document)

# 懒加载 -》 迭代器[Document]
for document in loader.lazy_load():
    print(type(document), document)