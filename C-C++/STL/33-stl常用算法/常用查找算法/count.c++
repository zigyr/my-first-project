#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//统计内置数据类型
void test01(){
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);
    cout<<count(v.begin(),v.end(),40)<<endl;
}

//统计自定义数据类型
class Person{
public:
    Person(string name,int age){
        this->m_Name=name;
        this->m_Age=age;
    }
    //重载const成员函数
    bool operator==(const Person& p){
        if(this->m_Age==p.m_Age){
            return true;
        }else{
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
void test02(){
    vector<Person>v;
    Person p1("aaa",35);
    Person p2("bbb",35);
    Person p3("ccc",35);
    Person p4("ddd",30);
    Person p5("eee",40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    Person p("bbb",35);
    cout<<count(v.begin(),v.end(),p)<<endl;
}
int main (){
    test01();
    test02();
}