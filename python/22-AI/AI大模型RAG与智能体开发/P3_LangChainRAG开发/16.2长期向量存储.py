from langchain_community.embeddings import DashScopeEmbeddings
from langchain_community.document_loaders import CSVLoader
from langchain_chroma import Chroma

# 轻量级的向量数据库 Chroma
# pip install langchain_chroma chromadb

vector_store = Chroma(
    collection_name = "test",    # 当前向量存储的名字, 类似数据库的表名称
    embedding_function = DashScopeEmbeddings(),    # 嵌入模型
    persist_directory = r"F:\code_practice\code\python\AI大模型RAG与智能体开发\P3_LangChainRAG开发\chroma_db",
    # 作为Chroma 的「数据仓库」，既是写入数据的出口，也是读取数据的入口
)

# loader = CSVLoader(
#     file_path = r"F:\code_practice\code\python\AI大模型RAG与智能体开发\P3_LangChainRAG开发\data\info.csv",
#     encoding = 'utf-8',
#     source_column = "source",    # 决定metadata中source的内容
#     # 注意csv编写时的修饰性空格会影响`source_column`与`metadata[source]`中的内容
# )

# documents = loader.load()

# # 新增
# vector_store.add_documents(
#     documents = documents,
#     ids = ["id" + str(i) for i in range(1, len(documents) + 1)]
# )

# # 删除
# vector_store.delete(["id1", "id2"])

# 检索
result = vector_store.similarity_search(
    "Python是不是简单易学呀",
    3,
    filter = {"source": "黑马程序员"}    # 只能过滤metadata字段
)

print(result[0])