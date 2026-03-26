from openai import OpenAI
import os

client = OpenAI(
    # 如果没有配置环境变量，请用阿里云百炼API Key替换：api_key="sk-xxx"
    base_url="https://dashscope.aliyuncs.com/compatible-mode/v1",
)

messages = [{"role": "user", "content": "你是谁"}]
completion = client.chat.completions.create(
    model="deepseek-v3",  
    messages=messages,
    stream=True
)


for chunk in completion:
    print(chunk.choices[0].delta.content, end="", flush=True)

"""
OPENAI_API_KEY = 
DASHSCOPE_API_KEY = 
"""