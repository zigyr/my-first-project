/*
无论是 内置数据类型排序 还是 自定义数据类型排序
都是构造 仿函数 来实现的
或者 用function包装lambda
*/
#include <iostream>
#include <set>
using namespace std;
#include <string>

//set容器排序：内置数据类型
class Number{
public:
    int x;
    Number(int x_) : x(x_) {}
    bool operator <(const Number& num)const{
        return x < num.x;  // 升序
    }
};

void test01(){
    set<Number>s2;
    Number n1(10); s2.insert(n1);
    Number n2(20); s2.insert(n2);
    Number n3(30); s2.insert(n3);
    Number n4(40); s2.insert(n4); 

    for(set<Number>::iterator dit=s2.begin();dit!=s2.end();dit++){
        cout<<(*dit).x<<" ";
    }
    cout<<endl;
}

//set容器排序：自定义数据类型
class Person{
public:
    string m_Name;
    int m_Age;
    Person(string _m_Name, int _m_Age) : m_Name(_m_Name), m_Age(_m_Age) {}
    bool operator <(const Person& p)const{
        return m_Age > p.m_Age;  // 降序
    }
};

void test02(){
    set<Person>s3;
    Person p1("aaa",24);    s3.insert(p1);
    Person p2("bbb",28);    s3.insert(p2);
    Person p3("ccc",25);    s3.insert(p3);
    Person p4("ddd",21);    s3.insert(p4);
    for(set<Person>::iterator cit=s3.begin();cit!=s3.end();cit++){
        cout<<"name: "<<cit->m_Name<<" age: "<<cit->m_Age<<endl;
    }
}

int main (){
    test01();
    test02();
}