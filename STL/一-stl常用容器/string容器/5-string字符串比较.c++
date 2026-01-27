#include <iostream>
#include <string>
using namespace std;

void test01(){
    string str1="zello";
    string str2="xello";

    if(str2.compare(str1)==0){
        cout<<"str1=str2"<<endl;
    }else if(str2.compare(str1)>0){
        cout<<"str1<str2"<<endl;
    }else{
        cout<<"str1>str2"<<endl;
    }
}

int main (){
    test01();
}