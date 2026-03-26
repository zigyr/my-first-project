from langchain_community.llms.tongyi import Tongyi

model = Tongyi(model = "qwen-max")

# 通过stream方法获得流式输出
res = model.stream(input = "你是谁呀？能做什么？")

for chunk in res:
    print(chunk, end = "", flush = True)

"""
# ollama
from langchain_ollama import OllamaLLM
model = OllamaLLM(model = "qwen3:4b")
res = model.stream(input = "你是谁")
for chunk in res:
    print(chunk, end = "", flush = true)
"""