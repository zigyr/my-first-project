#include <iostream>
using namespace std;
#include <functional>

//negate 一元取反仿函数 
void test01(){
    negate<int>n;
    cout<<n(50)<<endl;
}

//plus 二元加法仿函数
void test02(){
    plus<int>p;
    cout<<p(10,10)<<endl;
}

//minus 二元减法仿函数
void test03(){
    minus<int>m;
    cout<<m(50,30)<<endl;
}

//multiplies 乘法仿函数
//divides    除法仿函数
//modulus    取模仿函数

int main (){
    test01();
    test02();
    test03();
}