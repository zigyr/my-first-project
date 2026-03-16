import requests

url = "https://www.icve.com.cn/prod-api/homePage/zykCourseList?pageSize=16&pageNum=1&courseName=茶艺"

headers={
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/142.0.0.0 Safari/537.36 Edg/142.0.0.0",
    # "Referer":"https://www.icve.com.cn/search",
    "Cookie":"aliyungf_tc=c37d87354c704a20a9c07f014c8970df8b317bcd54fb25f3b026a613b9a17216; acw_tc=ac11000117642112887841120e003522a479d6d92a72e06b2feb280e0951c1"
}

response=requests.get(url,headers=headers)

data=response.json()

# print(type(data),data)

# print(data["rows"])

with open("智慧职教.txt", "a", encoding='utf-8') as f:
    for i in data["rows"]:
        # print(f"这门{i['courseName']},是由{i['schoolName']},{i['teacherName']}教的")
        f.write(f"这门{i['courseName']},是由{i['schoolName']},{i['teacherName']}教的\n")