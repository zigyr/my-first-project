from openai import OpenAI
import os

api_key = os.getenv("DEEPSEEK_API_KEY")

client = OpenAI(
    api_key = api_key,
    base_url = "https://api.deepseek.com/v1"
)

response = client.chat.completions.create(
    model = "deepseek-chat",
    messages = [
        {
            "role": "system",
            "content": '处理英文术语：1转原形；2修正拼写；3计算机中译；4按A通用/B Linux/C Web安全分类；5保留短语。输出一行JSON：[{"e":"英文","c":"中文","t":"类别"}]，无多余内容'
        },
        {
            "role": "user",
            "content": """
load balancers
a failover
periodic checks
an enterprise scale
respond appropriately
clusters of multiple servers
resilience
Web Application Firewall
back slash
be mapped to
underscore
come to a crawl
take for example a blog
the latest entries
scripting languages
and so much more
Yay/Nay
virtual hosts
"""
        }
    ]
)

data = response.choices[0].message.content
print(data)