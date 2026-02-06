# 1连接数据库 2拿到游标 3执行sql语句 4关闭游标与数据库
import sqlite3

#连接
conn=sqlite3.connect('test.db')

#拿到游标
cursor=conn.cursor()

#执行sql
sql= "select * from user"
cursor.execute(sql)

result=cursor.fetchall()
print(result)

for i in result:
    print("我是%d号,我叫%s" % i)
    # print("我是%d号,我叫%s" % (i[0],i[1]))

#关闭游标与连接
cursor.close()
# conn.commit()
conn.close()