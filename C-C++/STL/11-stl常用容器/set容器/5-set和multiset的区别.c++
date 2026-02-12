#include <iostream>
#include <set>
using namespace std;

void test01(){
    set<int>s;
    // 通过pair 利用set容器的底层特性
    // 如果插入成功 pair变量的bool为true
    // 否则为false
    pair<set<int>::iterator,bool> ret=s.insert(10);//first
    if(ret.second){
        cout<<"success"<<endl;
    }else{
        cout<<"fail"<<endl;
    }
    ret=s.insert(10);//second
    if(ret.second){
        cout<<"success"<<endl;
    }else{
        cout<<"fail"<<endl;
    }

    multiset<int>ms;
    ms.insert(10);
    ms.insert(10);
    ms.insert(10);
    for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main (){
    test01();
}