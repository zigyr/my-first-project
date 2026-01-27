//sort的前两个参数确定了左闭右开的目标区间
//v.end()是目标元素的下一个位置，所以满足右开的条件
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <functional>

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int>v;
    v.push_back(10);
    v.push_back(60);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);

    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;

    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}

int main (){
    test01();
}