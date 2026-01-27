#include <iostream>
#include <set>
using namespace std;
#include <string>

//set容器排序：内置数据类型
class myCompare{
public:
    bool operator()(int v1,int v2)const{
        return v1>v2;
    }
};

void test01(){
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    for(set<int>::iterator it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    set<int,myCompare>s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(30);
    s2.insert(40);

    for(set<int,myCompare>::iterator dit=s2.begin();dit!=s2.end();dit++){
        cout<<*dit<<" ";
    }
    cout<<endl;
}

//set容器排序：自定义数据类型
class Person{
public:
    Person(string name,int age){
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};

class comparePerson{
public:
    bool operator()(const Person& p1,const Person& p2)const{
        return p1.m_Age>p2.m_Age;
    }
};

void test02(){
    set<Person,comparePerson>s3;
    Person p1("aaa",24);
    Person p2("bbb",28);
    Person p3("ccc",25);
    Person p4("ddd",21);
    s3.insert(p1);
    s3.insert(p2);
    s3.insert(p3);
    s3.insert(p4);
    for(set<Person,comparePerson>::iterator cit=s3.begin();cit!=s3.end();cit++){
        cout<<"name: "<<cit->m_Name<<" age: "<<cit->m_Age<<endl;
    }
}

int main (){
    test01();
    test02();
}