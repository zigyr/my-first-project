#ua检测
import requests

url = 'http://www.cpta.com.cn/'
headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36 Edg/142.0.0.0"
}

response = requests.get(url,headers=headers)
response.encoding='utf-8'
with open("人事考试.html","w",encoding='utf-8') as f:
    f.write(response.text)
#打开的html上的数据之所以加载不出来，
#是因为关于图片的路径是相对路径，
#不像其他网页是写www开头的图片路径