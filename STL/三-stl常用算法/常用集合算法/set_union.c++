#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//并集

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int>v1,v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+2);
    }
    vector<int>v;
    
    v.resize(v1.size()+v2.size());
    
    //返回目标容器最后一个元素的迭代器的地址
    vector<int>::iterator itEnd=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
    
    for_each(v.begin(),itEnd,myPrint);
    cout<<endl;
}

int main (){
    test01();
}