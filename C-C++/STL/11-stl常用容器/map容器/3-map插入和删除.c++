#include <iostream>
#include <map>
using namespace std;

void printMap(const map<int,int>& m){
    for(const auto& a:m){
        cout<<"key= "<<a.first<<" value= "<<a.second<<endl;
    }
    cout<<endl;
}

void test01(){
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));
    m.insert(map<int,int>::value_type(5,50));
    m[6]=60;
    //不建议通过[]插入，建议用[]通过key访问value
    cout<<m[7]<<endl;
    printMap(m);

    m.erase(m.begin());
    printMap(m);

    //按照key值
    m.erase(3);
    printMap(m);

    m.clear();
    // m.erase(m.begin(),m.end());
    printMap(m);

}

int main (){
    test01();
}