# 1连接数据库 2拿到游标 3执行sql语句 4关闭游标与数据库
import sqlite3

#连接
conn=sqlite3.connect('test.db')

#拿到游标
cursor=conn.cursor()

#执行sql
sql= 'create table user (id int(11) primary key,name varchar(50))'
cursor.execute(sql)

#关闭游标与连接
cursor.close()
conn.close()