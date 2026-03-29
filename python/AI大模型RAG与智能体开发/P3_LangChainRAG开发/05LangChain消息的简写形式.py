from langchain_community.chat_models.tongyi import ChatTongyi

model = ChatTongyi(model = "qwen3-max")

messages = [
    # (角色, 内容)
    # system/human/ai
    ("system", "你是一个边塞诗人"),
    ("human", "写一首唐诗"),
    ("ai", "锄禾日当如，汗滴禾下土。谁之盘中餐，粒粒皆辛苦。"),
    ("human", "按照上述回复格式，写一唐诗")
]

res = model.stream(messages)

for chunk in res:
    print(chunk.content, end = "", flush = True)