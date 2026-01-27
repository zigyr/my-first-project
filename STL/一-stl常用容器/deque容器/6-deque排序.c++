#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(const deque<int>& d){
    for(const auto& a:d){
        cout<<a<<" ";
    }
    cout<<endl;
}

void test01(){
    deque<int>d;
    d.push_back(10);
    d.push_back(40);
    d.push_front(90);
    d.push_front(100);
    cout<<"before sorting:::"<<endl;
    printDeque(d);
    cout<<"after sortin:::"<<endl;
    sort(d.begin(),d.end());
    printDeque(d);
}

int main (){
    test01();
}