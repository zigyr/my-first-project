#include <iostream>
#include <list>
using namespace std;

void test01(){
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    
    //L1[0];unsupport
    //L1.at(0);unsupport
    cout<<L1.front()<<endl;
    cout<<L1.back()<<endl;

    list<int>::iterator it=L1.begin();
    it++;//支持双向访问
    it--;
    //it=it+1;不支持随机访问
}

int main (){
    test01();
}