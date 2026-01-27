#include <iostream>
#include <list>
#include <string>
using namespace std;

//按照年龄进行升序，如果年龄相同，则按照身高排序

class Person{
public:
    Person(string name,int age,int height){
        this->m_Name=name;
        this->m_Age=age;
        this->m_Height=height;
    }
    string m_Name;
    int m_Age;
    int m_Height;    
};

void printList(const list<Person>& L){
    for(const auto& a:L){
        cout<<a.m_Name<<" "<<a.m_Age<<" "<<a.m_Height<<endl;
    }
    cout<<endl;
}

bool comparePerson(Person& p1,Person& p2){
    if(p1.m_Age==p2.m_Age)return p1.m_Height>p2.m_Height;
    return p1.m_Age<p2.m_Age;
}

void test01(){
    list<Person>L;

    Person p1("aaa",35,175);
    Person p2("bbb",45,180);
    Person p3("ccc",40,170);
    Person p4("ddd",25,190);
    Person p5("eee",35,160);
    Person p6("fff",35,200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    printList(L);

    cout<<"after sorted"<<endl;
    L.sort(comparePerson);

    printList(L);
}

int main (){
    test01();
}