#include <iostream>
using namespace std;
#include <algorithm>

//搭配count_if可以实现
//判断一个int数组的有效元素个数
void test01(){
    int num01[10];
    fill(num01,num01+10,-1);
    for(int i=0;i<6;i++){
        num01[i]=i;
    }
    cout<<count_if(num01,num01+10,[](int x){return x!=-1;});
}

int main (){
    int num[10];
    fill(num,num+10,-1);
    for(const auto& a:num){
        cout<<a<<" ";
    }
    test01();
}