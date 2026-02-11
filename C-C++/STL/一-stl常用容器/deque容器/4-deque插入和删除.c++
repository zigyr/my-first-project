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
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(200);
    d1.push_front(100);
    printDeque(d1);

    d1.pop_back();
    d1.pop_front();
    printDeque(d1);

    d1.insert(d1.begin(),1000);
    printDeque(d1);

    d1.insert(d1.begin(),2,10000);
    printDeque(d1);

    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(),d2.begin(),d2.end());
    printDeque(d1);

    d1.erase(d1.begin());
    printDeque(d1);

    // d1.erase(d1.begin(),d1.end());
    d1.clear();
    printDeque(d1);
}

int main (){
    test01();
}