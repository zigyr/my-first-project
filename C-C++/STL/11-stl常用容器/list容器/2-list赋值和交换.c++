#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>& L){
    for(const auto& a:L){
        cout<<a<<" ";
    }
    cout<<endl;
}

void test01(){
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    list<int>L2;
    L2=L1;
    printList(L2);

    list<int>L3;
    L3.assign(L2.begin(),L2.end());
    printList(L3);

    list<int>L4;
    L4.assign(10,100);
    printList(L4);

    cout<<"before swap:"<<endl;
    printList(L3);
    printList(L4);
    cout<<"after swap"<<endl;
    L3.swap(L4);
    printList(L3);
    printList(L4);
}

int main (){
    test01();
}