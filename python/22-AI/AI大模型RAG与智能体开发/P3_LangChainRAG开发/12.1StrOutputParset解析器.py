from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import PromptTemplate
from langchain_community.chat_models.tongyi import ChatTongyi
from langchain_core.messages import AIMessage

model = ChatTongyi(model = "qwen3-max")

parser = StrOutputParser()

prompt = PromptTemplate.from_template(
    "我的邻居姓：{lastname}，刚生了{gender}宝宝，请起名。仅告知我名字即可"
)

# chain = prompt | model | parser | model

# res: AIMessage = chain.invoke({"lastname": "李", "gender": "女"})

# print(res.content)
# print(type(res))

chain = prompt | model | parser | model | parser

res: str = chain.invoke({"lastname": "李", "gender": "女"})

print(res)
print(type(res))