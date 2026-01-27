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
    L1.push_front(2);
    L1.push_front(1);
    printList(L1);

    L1.pop_front();
    printList(L1);

    L1.insert(L1.begin(),1000);
    printList(L1);

    list<int>::iterator it=L1.begin();
    it++;
    L1.insert(it,2000);
    printList(L1);

    L1.erase(L1.begin());
    printList(L1);

    L1.push_back(100);
    L1.push_front(100);
    printList(L1);
    L1.remove(100);
    printList(L1);

    L1.clear();
    printList(L1);
}

int main (){
    test01();
}