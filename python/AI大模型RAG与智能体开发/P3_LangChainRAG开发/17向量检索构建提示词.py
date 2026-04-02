from langchain_community.chat_models import ChatTongyi
from langchain_community.embeddings import DashScopeEmbeddings
from langchain_core.vectorstores import InMemoryVectorStore
from langchain_core.prompts import ChatPromptTemplate
from langchain_core.output_parsers import StrOutputParser

"""
提示词 = 用户提问 + 向量库中检索到的参考资料
"""

model = ChatTongyi(model = "qwen3-max")

prompt = ChatPromptTemplate.from_messages(
    [
        ("system", "以我提供的已知参考资料为主, 简介且专业的回答用户问题. 参看资料：{context}"),
        ("user", "用户提问：{input}")
    ]
)

vector_store = InMemoryVectorStore(
    embedding = DashScopeEmbeddings(model = "text-embedding-v4")
)

# 准备一下向量数据库的内容
# add_texts 传入一个列表 list[str]
vector_store.add_texts(
    [
        "减肥就是要少吃多练",
        "在减脂期间吃东西很重要, 清淡少油控制卡路里摄入并运动起来",
        "跑步是很好的运动欧"
    ]
)

# 结合用户提问, 对参考资料进行检索筛查
input_text = "如何减肥"
result = vector_store.similarity_search(input_text, 2)
# print(result)

# 构建筛查后的参考资料
reference_text = "["
for doc in result:
    reference_text += doc.page_content
reference_text += "]"
# print(reference_text)

# chain
def print_prompt(prompt):
    print(prompt.to_string())
    print("=" * 20)
    return prompt

chain = prompt | print_prompt | model | StrOutputParser()

res = chain.invoke(
    {
        "input": input_text,
        "context": reference_text
    }
)

print(res)