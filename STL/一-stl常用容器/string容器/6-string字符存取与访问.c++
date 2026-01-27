#include <iostream>
#include <string>
using namespace std;

void test01(){
    string str="hello";
    cout<<"str = "<<str<<endl;

    //逐步打印每个字符
    //方法一：通过[]访问
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    //方法二：通过at访问
    for(int i=0;i<str.size();i++){
        cout<<str.at(i)<<" ";
    }
    cout<<endl;

    //修改单个字符
    str[0]='x';
    cout<<"str = "<<str<<endl;
    str.at(1)='x';
    cout<<"str = "<<str<<endl;
}

int main (){
    test01();
}