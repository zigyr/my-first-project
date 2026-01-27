#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int>& d){
    for(const auto& a:d){
        cout<<a<<" ";
    }
    cout<<endl;
}

void test01(){
    deque<int>d1;
    for(int i=0;i<10;i++){
        d1.push_back(i);
    }
    printDeque(d1);

    if(d1.empty()){
        cout<<"empty"<<endl;
    }else{
        cout<<"unempty"<<endl;
        cout<<"this size is:"<<d1.size()<<endl;
    }

    d1.resize(15,1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

int main (){
    test01();
}