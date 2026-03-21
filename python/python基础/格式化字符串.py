# 旧式 % 格式化
name = "Alice"
age = 25
old_style = "My name is %s and I'm %d years old." % (name, age)
print(old_style)
 
# str.format() 方法
new_style = "My name is {} and I'm {} years old.".format(name, age)
print(new_style)
 
# f-string
f_string = f"My name is {name} and I'm {age} years old."
print(f_string)