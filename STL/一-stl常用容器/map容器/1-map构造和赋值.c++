#include <iostream>
#include <map>
using namespace std;

void printMap(const map<int,int>& m){
    for(const auto& a:m){
        cout<<a.first<<" "<<a.second<<endl;
    }
    cout<<endl;
}

void test01(){
    map<int,int>m;
    //key值自动排序
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(4,40));
    printMap(m);

    map<int,int>m2(m);
    printMap(m2);

    map<int,int>m3=m;
    printMap(m3);
}

int main (){
    test01();
}