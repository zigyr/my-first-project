from langchain_community.document_loaders import PyPDFLoader

loader = PyPDFLoader(
    file_path = "F:\\code_practice\\code\\python\\AI大模型RAG与智能体开发\\P3_LangChainRAG开发\\data\\pdf1.pdf",
    mode = "single",    # single模式, 不管有多少页, 只返回一个Document对象
    # mode = "page",      # 默认是page模式, 每个页面形成一个Document文档对象

    password = "zigyr"
)

for i, doc in enumerate(loader.lazy_load()):
    print(doc)
    print("=" * 20)