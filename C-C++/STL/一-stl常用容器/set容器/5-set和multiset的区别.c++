#include <iostream>
#include <set>
using namespace std;

void test01(){
    set<int>s;
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