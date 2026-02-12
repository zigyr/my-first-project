#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int>v;
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    for(int i=10;i<20;i++){
        v2.push_back(i);
    }

    //提前给目标容器分配内存空间
    v.resize(v1.size()+v2.size());

    //两个容器元素合并，并储存到另一个容器
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());

    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}

int main (){
    test01();
}