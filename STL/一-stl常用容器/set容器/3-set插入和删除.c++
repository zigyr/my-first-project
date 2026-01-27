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
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(40);
    printSet(s1);

    // s1.erase(s1.begin(),s1.end());
    s1.clear();
    printSet(s1);

}

int main (){
    test01();
}