from langchain_core.output_parsers import StrOutputParser, JsonOutputParser
from langchain_community.chat_models.tongyi import ChatTongyi
from langchain_core.prompts import PromptTemplate

model = ChatTongyi(model = "qwen3-max")

str_parser = StrOutputParser()
json_parser = JsonOutputParser()

first_prompt = PromptTemplate.from_template(
    "我的邻居姓：{lastname}，刚生了{gender}宝宝，请起名。仅告知我名字即可" 
    "并且封装为JSON格式返回，要求Key是name，Value是你起的名字。请严格按照要求"
)

second_prompt = PromptTemplate.from_template(
    "姓名：{name}。请解析含义"
)

# # 部分chain的invoke演示
# chain = first_prompt | model | json_parser
# res = chain.invoke({"lastname": "李", "gender": "女"})
# print(res)
# print(type(res))


# # 完整chain的invoke演示
# chain = first_prompt | model | json_parser | second_prompt | model | str_parser
# res = chain.invoke({"lastname": "李", "gender": "女"})
# print(res)
# print(type(res))


# 完整chain的stream演示
chain = first_prompt | model | json_parser | second_prompt | model | str_parser
for chunk in chain.stream({"lastname": "李", "gender": "女"}):
    print(chunk, end = "", flush = True)
