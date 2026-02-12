#include <iostream>
using namespace std;
#include <vector>
#include <functional>
#include <algorithm>
void test01(){
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    for(vector<bool>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    
    //利用 逻辑非logical_not 将容器v元素搬运到容器v2 并执行取反操作
    vector<bool>v2;

    v2.resize(v.size());

    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    for(vector<bool>::iterator it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main (){
    test01();
}