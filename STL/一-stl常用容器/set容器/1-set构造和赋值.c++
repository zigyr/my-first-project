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
    s1.insert(30);
    s1.insert(40);
    s1.insert(20);
    printSet(s1);

    set<int>s2(s1);
    printSet(s2);

    set<int>s3=s2;
    printSet(s3);
}

int main (){
    test01();
}