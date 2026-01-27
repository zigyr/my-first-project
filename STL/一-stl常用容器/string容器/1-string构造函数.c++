#include <iostream>
using namespace std;
#include <string>
void test01(){
    //一：默认构造
    string s1;

    //二
    const char * str="hello world!";
    string s2(str);
    cout<<"s2="<<s2<<endl;

    //三
    string s3(s2);
    cout<<"s3="<<s3<<endl;
    
    //四
    string s4(5,'c');
    cout<<"s4="<<s4<<endl;    
}

int main (){
    test01();
}