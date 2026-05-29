from langchain_community.embeddings import DashScopeEmbeddings
from langchain_community.document_loaders import CSVLoader
from langchain_core.vectorstores import InMemoryVectorStore

vector_store = InMemoryVectorStore(
    embedding = DashScopeEmbeddings()
)

loader = CSVLoader(
    file_path = r"F:\code_practice\code\python\AI大模型RAG与智能体开发\P3_LangChainRAG开发\data\info.csv",
    encoding = 'utf-8',
    source_column = "source",    # 决定metadata中source的内容
    # 注意csv编写时的修饰性空格会影响`source_column`与`metadata[source]`中的内容
)

documents = loader.load()

# 向量存储的 新增、删除、检索
vector_store.add_documents(
    documents = documents,
    ids = ["id" + str(i) for i in range(1, len(documents) + 1)]
)

# 删除
vector_store.delete(["id1", "id2"])

# 检索
result = vector_store.similarity_search(
    "Python是不是简单易学呀",
    3
)

print(result)