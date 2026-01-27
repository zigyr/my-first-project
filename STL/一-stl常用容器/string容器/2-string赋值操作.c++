#include <iostream>
using namespace std;
#include <string>

void test01(){
    //一
    string str1;
    str1="hello world";
    cout<<"str1 = "<<str1<<endl;

    //二
    string str2;
    str2=str1;
    cout<<"str2 = "<<str2<<endl;

    //三
    string str3;
    str3='a';
    cout<<"str3 = "<<str3<<endl;

    //四（同一）
    string str4;
    str4.assign("hello, C++");
    cout<<"str4 = "<<str4<<endl;

    //五
    string str5;
    //将字符串的前6位存入str5中
    str5.assign("hello, C++",6);
    cout<<"str5 = "<<str5<<endl;

    //六（同二）
    string str6;
    str6.assign(str5);
    cout<<"str6 = "<<str6<<endl;

    //七（同三）
    string str7;
    //五个字符'c'
    str7.assign(5,'c');
    cout<<"str7 = "<<str7<<endl;
}

int main (){
    test01();
}