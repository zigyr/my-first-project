import json


d = {
    "name": "周杰伦",
    "age": 11,
    "gender": "男"
}
l = [
    {
        "name": "周杰伦",
        "age": 11,
        "gender": "男"
    },
    {
        "naem": "蔡依林",
        "age": 12,
        "gender": "女"
    }
]

list_str = json.dumps(l, ensure_ascii = False)
dict_str = json.dumps(d, ensure_ascii = False)
print(list_str, type(list_str))
print(dict_str, type(dict_str))
# `json.dumps(字典或列表, ensure_ascii= False)`
# 将字典或列表转换成Json字符串
# ensure_ascii = False 确保中文能够正常显示


json_list_str = '[{"name": "周杰伦", "age": 11, "gender": "男"}, {"naem": "蔡依林", "age": 12, "gender": "女"}]'
json_dict_str = '{"name": "周杰伦", "age": 11, "gender": "男"}'

print(json.loads(json_list_str), type(json.loads(json_list_str)))
print(json.loads(json_dict_str), type(json.loads(json_dict_str)))
# `json.loads(json字符串)`
# 将Json字符串转换成字典或列表