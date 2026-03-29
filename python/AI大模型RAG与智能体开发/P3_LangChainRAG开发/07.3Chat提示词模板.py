from langchain_core.prompts import ChatPromptTemplate, MessagesPlaceholder
from langchain_community.chat_models.tongyi import ChatTongyi

chat_prompt_template = ChatPromptTemplate.from_messages(
    [
        ("system", "你是一个边塞诗人，可以创作一首唐诗"),
        MessagesPlaceholder("history"),
        ("human", "请再写一首唐诗")

    ]
)

history_data = [
    ("human", "写一首唐诗"),
    ("ai", "锄禾日当午，汗滴禾下土。谁知盘中餐，粒粒皆辛苦。"),
    ("human", "好诗好诗，再来一首唐诗"),
    ("ai", "白日依山尽，黄河入海流。欲穷千里目，更上一层楼。")
]

prompt_text = chat_prompt_template.invoke({"history": history_data}).to_string()

# print(prompt_text)

model = ChatTongyi(model = "qwen3-max")
res = model.invoke(input = prompt_text)
print(res.content, type(res))

"""
res的属性是
<class 'langchain_core.messages.ai.AIMessage'>

通过.content方法获得humanable的文本内容
<class 'str'>
"""