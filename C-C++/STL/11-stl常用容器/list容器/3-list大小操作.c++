#include <list>
#include <iostream>
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
    cout<<L1.size()<<endl;

    if(L1.empty()){
       cout<<"empty"<<endl; 
    }else{
        cout<<"unempty"<<endl;
    }

    L1.resize(15,10);
    printList(L1);

    L1.resize(3);
    printList(L1);

}

int main (){
    test01();
}

