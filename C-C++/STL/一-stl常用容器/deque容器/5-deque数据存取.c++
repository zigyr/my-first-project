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
    deque<int>d;
    for(int i=0;i<10;i++){
        d.push_back(i);
    }

    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<d.size();i++){
        cout<<d.at(i)<<" ";
    }
    cout<<endl;

    cout<<"first position:"<<d.front()<<endl;
    cout<<"last position:"<<d.back()<<endl;
}

int main (){
    test01();
}