#include <iostream>
#include <queue>
using namespace std;

class Person{
public:
    Person(string name,int age){
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};

void test01(){
    queue<Person>q;

    Person p1("job",11);
    Person p2("bob",21);
    Person p3("aob",31);
    Person p4("cob",41);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout<<"the size of the queue is:"<<q.size()<<endl;

    while(!q.empty()){
        cout<<"name of the front of the queue is:"<<q.front().m_Name<<", age is:"<<q.front().m_Age<<endl;
        cout<<"name of the back of the queue is:"<<q.back().m_Name<<", age is:"<<q.back().m_Age<<endl;
        q.pop();
    }

    cout<<"the size of the queue is:"<<q.size()<<endl;
}

int main (){
    test01();
}