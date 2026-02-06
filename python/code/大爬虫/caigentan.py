import requests
from lxml import etree
import os

url = 'https://caigentan.5000yan.com/'

headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36 Edg/142.0.0.0",
    "Referer":""
}

response=requests.get(url,headers=headers)
response.encoding='utf-8'

tree=etree.HTML(response.text)
a_tags=tree.xpath('/html/body/div[2]/div/div[1]/div[4]/div[2]')
print(a_tags)

# novel_folder="caigentan"
# os.mkdir(novel_folder)


# for i in a_tags:
#     title=i.xpath('./a/text()')[0]
#     detail_url=i.xpath('./a/@href')[0]
#
#     detail_response=requests.get(detail_url,headers=headers)
#     detail_response.encoding='utf-8'
#
#     detail_tree=etree.HTML(detail_response.text)
#     content_list=detail_tree.xpath("/html/body/div[2]/div[1]/div[1]/div[3]/div[4]/p[2]/text()")
#
#     content = ''.join(content_list)
#     with open(os.path.join(base_dir,f"{title}.txt"),"w",encoding="utf-8") as f:
#         f.write({content)
#         print(f"{title}下载完成")