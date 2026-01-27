#include <iostream>
#include <set>
using namespace std;

void printSet(const set<int>& s){
    for(const auto& a:s){
        cout<<a<<" ";
    }
    cout<<endl;
}

void test01(){
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    printSet(s1);

    if(s1.empty()){
        cout<<"empty"<<endl;
    }else{
        cout<<"unempty"<<endl;
        cout<<s1.size()<<endl;
    }

    set<int>s2;
    s2.insert(300);
    s2.insert(400);
    s2.insert(200);
    s2.insert(100);
    printSet(s2);

    cout<<"after sorted"<<endl;
    s1.swap(s2);
    printSet(s1);
    printSet(s2);

}

int main (){
    test01();
}