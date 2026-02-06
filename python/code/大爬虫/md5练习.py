from hashlib import md5

data="12345"
obj=md5()
obj.update(data.encode("utf-8"))
ret=obj.hexdigest()
print(ret)