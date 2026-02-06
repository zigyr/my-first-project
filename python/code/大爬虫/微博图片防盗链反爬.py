import requests
from lxml import etree

url=''

headers={
    "User-Agent":"",
    "Referer":""
}

response=requests.get(url,headers=headers)
response.text.encode('utf-8')
tree=etree.HTML(response.text)
a_tags=tree.xpath("")
for a_tag in a_tags:
    title=a_tag.xpath()[0]
    detail_url=a_tag.xpath()[0]
    data=requests.get(detail_url,headers=headers).content
    with open("123.png","wb") as f:
        f.write(data)
