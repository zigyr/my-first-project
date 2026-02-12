#include <iostream>
#include <vector>
//需要头文件numeric
#include <numeric>
using namespace std;

void test01(){
    vector<int>v;
    for(int i=0;i<=100;i++){
        v.push_back(i);
    }
    //第三个参数 作为累加的起始值
    cout<<accumulate(v.begin(),v.end(),0)<<endl;
    cout<<accumulate(v.begin(),v.end(),1000)<<endl;
}

int main (){
    test01();
}