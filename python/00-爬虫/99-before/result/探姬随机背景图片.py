import requests
import os

url="http://www.dmoe.cc/random.php"

img_dir="test_img"
os.makedirs(img_dir,exist_ok=True)

for i in range (1,10):
    response=requests.get(url)
    img_name=f"{i+10}.png"
    with open(os.path.join(img_dir,img_name),"wb") as f:
        f.write(response.content)
    print(f"{img_name}：已打印完成！！！")