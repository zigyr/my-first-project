#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//查找指定元素是否存在
void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    // v.push_back(2);
    // 必须是有序的序列
    bool ret=binary_search(v.begin(),v.end(),9);
    if(ret){
        cout<<"find"<<endl;
    }else{
        cout<<"dis find"<<endl;
    }
}

int main (){
    test01();
}