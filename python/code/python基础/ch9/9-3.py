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

#同文件下的文件，直接用from 文件名 import 类/函数
from TranError import TranError

try:
    # print(10/0)
    # a=b+1
    # a=1+1
    raise TranError(500001,'tranError')
except Exception as e:
    print(e)
else:
    print("no error")
finally:
    print("finally")

print("2")