#include <iostream>
#include <map>
using namespace std;

void printMap(map<int,int>& m){
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    if(m.empty()){
        cout<<"empty"<<endl;
    }else{
        cout<<"unempty"<<endl;
        cout<<m.size()<<endl;
    }
    printMap(m);

    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    map<int,int>m2;
    m2.insert(pair<int,int>(1,100));
    m2.insert(pair<int,int>(2,200));
    m2.insert(pair<int,int>(3,300));
    m2.insert(pair<int,int>(4,400));
    cout<<"before swap"<<endl;
    printMap(m1);
    printMap(m2);
    cout<<"after swap"<<endl;
    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}

int main (){
    test01();
}