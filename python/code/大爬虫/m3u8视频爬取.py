import requests
import m3u8
from urllib.parse import urljoin
from bs4 import BeautifulSoup

headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36 Edg/142.0.0.0",
    "Referer":"https://www.youporn.com/",
}
# print("请输入当前代理的端口号：")
# port=input()
proxies = {
    'http': f'http://127.0.0.1:8956',
    'https': f'http://127.0.0.1:8956'
}
# print("请输入要爬取的视频页面的url：")
# url=input()
url="https://www.youporn.com/watch/190854361/"
response=requests.get(url,headers=headers,proxies=proxies)
soup=BeautifulSoup(response.text,"lxml")
title=soup.title.string
# response.encoding='utf-8'
# with open("m3u8.html","wb")as f:
#     f.write(response.content)
# print("请输入要爬取的视频页面的f12开发者工具中有index、m3u8关键字的url：)
# m3u8_url=input()
m3u8_url="https://ev-h-ph.ypncdn.com/hls/videos/202409/17/457895811/720P_4000K_457895811.mp4/index-v1-a1.m3u8?validfrom=1764214549&validto=1764221749&hdl=-1&hash=gz26P%2FkaCMHfz%2F6LeuxGw7B9eu0%3D"
modle_url="https://ev-h-ph.ypncdn.com/hls/videos/202409/17/457895811/720P_4000K_457895811.mp4/master.m3u8?validfrom=1764214549&validto=1764221749&hdl=-1&hash=gz26P%2FkaCMHfz%2F6LeuxGw7B9eu0%3D"

response=requests.get(m3u8_url,headers=headers,proxies=proxies)
#
# m3u8_obj=m3u8.loads(response.text)
tt=requests.get(m3u8_url,headers=headers,proxies=proxies)
print(tt.text)
# ts_urls=[urljoin(modle_url,seg.uri) for seg in m3u8_obj.segments]
# print(ts_urls)
"""
with open(f"{title}.mp4","wb") as f:
    for idx,ts_url in enumerate(ts_urls):
        print(f"正在下载分片{idx+1}/{len(ts_urls)}")
        response=requests.get(ts_url,headers=headers,proxies=proxies)
        f.write(response.content)

print("视频下载完成")
"""


