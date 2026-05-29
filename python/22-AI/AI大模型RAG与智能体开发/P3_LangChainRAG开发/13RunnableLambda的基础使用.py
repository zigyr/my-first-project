from langchain_core.output_parsers import StrOutputParser
from langchain_core.prompts import PromptTemplate
from langchain_core.runnables import RunnableLambda
from langchain_community.chat_models.tongyi import ChatTongyi

str_parser = StrOutputParser()

model = ChatTongyi(model = "qwen3-max")

first_prompt = PromptTemplate.from_template(
    "我的邻居姓：{lastname}，刚生了{gender}宝宝，请起名。仅告知我名字即可"
)

second_prompt = PromptTemplate.from_template(
    "姓名：{name}。请解析含义"
)

# my_func = RunnableLambda(lambda ai_msg: {"name": ai_msg.content})
# chain = first_prompt | model | my_func | second_prompt | model | str_parser

chain = first_prompt | model | (lambda ai_msg: {"name": ai_msg.content}) | second_prompt | model | str_parser

for chunk in chain.stream({"lastname": "李", "gender": "女"}):
    print(chunk, end = "", flush = True)