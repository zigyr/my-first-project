import requests
import os

# API_KEY = os.getenv('DEEPSEEK_API_KEY')
url = 'https://ark.cn-beijing.volces.com/api/v3/chat/completions '

headers = {
    'Authorization': f"Bearer 4352f852-ce35-4800-a33e-ee4ff91f2e94",
    'Content-Type': 'application/json'
}

data = {
    'model': 'doubao-1-5-pro-256k-250115',
    'messages': [{
        "role": "user",
        "content": "你好，请帮我写一段python代码"
    }],
    "temperature": 0.7,
    "stream": False
}

response = requests.post(url, headers = headers, json = data)

if response.status_code == 200:
    result = response.json()
    print(result['choices'][0]['message']['content'])
else:
    print(f"请求失败，状态码: {response.status_code}, 错误信息: {response.text}")

"""
curl https://ark.cn-beijing.volces.com/api/v3/chat/completions \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer 4352f852-ce35-4800-a33e-ee4ff91f2e94" \
  -d '{
    "model": "doubao-1-5-pro-256k-250115",
    "messages": [
      {"role": "system","content": "你是人工智能助手."},
      {"role": "user","content": "你好"}
    ]
  }'
"""