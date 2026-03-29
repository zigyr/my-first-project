from langchain_core.prompts import PromptTemplate
from langchain_core.prompts import FewShotPromptTemplate
from langchain_core.prompts import ChatPromptTemplate

"""
PromptTemplate -> StringPromptTemplate -> BasePromptTemplate -> RunnableSerializable -> Runnable
FewShotPromptTemplate -> StringPromptTemplate -> BasePromptTemplate -> RunnableSerializable -> Runnable
ChatPromptTemplate -> BaseChatPromptTemplate -> BasePromptTemplate -> RunnableSerializable -> Runnable
"""

template = PromptTemplate.from_template("我的邻居是：{name}，最喜欢{hobby}")

res1 = template.format(name="小明", hobby="画画")               # 关键字传参
print(res1, type(res1))

res2_1 = template.invoke({"name": "小红", "hobby": "跳舞"})     # 字典传参
res2_2 = template.invoke({"name": "小红", "hobby": "跳舞"}).to_string()
print(res2_1, type(res2_1))
print(res2_2, type(res2_2))
