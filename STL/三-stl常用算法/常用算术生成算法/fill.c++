#include <iostream>
#include <vector>
#include <algorithm>
//需要头文件numeric
#include <numeric>
using namespace std;

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int>v;
    
    v.resize(10);
    //相对于resize的第二个参数，fill具有 灵活 的填充能力
    fill(v.begin(),v.end(),10);

    for_each(v.begin(),v.end(),myPrint); 
    cout<<endl;
}

int main (){
    test01();
}