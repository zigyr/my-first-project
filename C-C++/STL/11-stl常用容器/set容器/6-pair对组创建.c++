#include <iostream>
#include <string>
using namespace std;

void test01(){
    pair<string,int>p1("Bob",20);
    cout<<"name: "<<p1.first<<" age: "<<p1.second<<endl;

    pair<string,int>p2=make_pair("Tom",30);
    cout<<"name: "<<p2.first<<" age: "<<p2.second<<endl;
}

int main (){
    test01();
}