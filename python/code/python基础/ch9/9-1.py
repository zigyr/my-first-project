"""
try:
    程序执行语句块
except Exception as e:
    异常处理语句块
···
else:
    无异常时处理语句块
finally:
    必须的处理语句块
"""

try:
    print(10/0)
    a=b+1
    # a=1+1
except (NameError,ZeroDivisionError) as e:
    print(e)
except Exception as e:
    print(e)
else:
    print("no error")
finally:
    print("finally")

print("2")