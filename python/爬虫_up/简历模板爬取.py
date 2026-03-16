import requests
from lxml import etree
import time
import os

headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36 Edg/142.0.0.0"
}
BASE_dir="jianli"
for i in range(1,3):
    if i==1:
        url="https://sc.chinaz.com/jianli/free.html"
    else:
        url=f"https://sc.chinaz.com/jianli/free_{i}.html"

    response=requests.get(url=url,headers=headers)
    response.encoding='utf-8'
    tree=etree.HTML(response.text)
    lists=tree.xpath('//*[@id="container"]/div')
    for list in lists:
        # time.sleep(0.5)
        title=list.xpath('./p/a/text()')[0]
        detail_url=list.xpath('./p/a/@href')[0]

        detail_response=requests.get(url=detail_url,headers=headers)
        detail_tree=etree.HTML(detail_response.text)
        load_url=detail_tree.xpath('//*[@id="down"]/div[2]/ul/li[1]/a/@href')[0]
        data=requests.get(url=load_url,headers=headers).content
        with open(os.path.join(BASE_dir,f"{title}.rar"),'wb') as f:
            f.write(data)
            print(f"{title}，下载完毕！")