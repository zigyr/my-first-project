import requests

url = 'https://c-ssl.duitang.com/uploads/blog/202102/23/20210223111312_b79cc.jpg'

response=requests.get(url)

# print(response.content)

with open("深田永美.png", "wb") as f:
    f.write(response.content)