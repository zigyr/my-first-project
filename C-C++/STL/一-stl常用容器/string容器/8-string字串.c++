#include <iostream>
#include <string>
using namespace std;

void test01(){
    string str="abcdef";
    //从下标1处开始截取3个字符
    string subStr=str.substr(1,3);
    cout<<"subStr = "<<subStr<<endl;
}

int main (){
    // test01();

    //实用操作
    string email="lisi@beijing.com";
    //从邮箱地址中 获取用户名信息
    int pos=email.find('@');
    string userName=email.substr(0,pos);
    cout<<"userName = "<<userName<<endl;
}