# 1连接数据库 2拿到游标 3执行sql语句 4关闭游标与数据库
import sqlite3

#连接
conn=sqlite3.connect('test.db')

#拿到游标
cursor=conn.cursor()

#执行sql
sql= "insert into user (id,name) values ('2','张无忌')"
cursor.execute(sql)
sql= "insert into user (id,name) values ('3','令狐冲')"
cursor.execute(sql)
sql= "insert into user (id,name) values ('4','任盈盈')"
cursor.execute(sql)

#关闭游标与连接
cursor.close()
conn.commit()
conn.close()