#include <iostream>
#include <map>
using namespace std;

void test01(){
    //查找
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(3,40));

    map<int,int>::iterator pos=m.find(4);

    if(pos!=m.end()){
        cout<<"exist"<<endl;
        cout<<"key= "<<(*pos).first<<" value= "<<pos->second<<endl;
    }else{
        cout<<"unexist"<<endl;
    }

    //统计
    //不允许插入重复key元素
    //soso对于map容器的count统计结果而言，要么是0、要么是1
    int num=m.count(3);
    cout<<"num= "<<num<<endl;
}

int main (){
    test01();
}