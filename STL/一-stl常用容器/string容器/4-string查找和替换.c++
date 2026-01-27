#include <iostream>
using namespace std;
#include <string>

//查找
void test01(){
    //find从左往右
    string str1="abcdef";
    // int pos=str1.find("df");
    // if(pos==-1){
    size_t pos = str1.find("df");
    if(pos==string::npos){
        cout<<"该字符不存在"<<endl;
    }else{
        cout<<"pos = "<<pos<<endl;
    }

    //rfind从右往左
    string str2="abcdefde";
    int pos_find=str2.find("de");
    int pos_rfind=str2.rfind("de");
    cout<<"pos_find = "<<pos_find<<endl;
    cout<<"pos_rfind = "<<pos_rfind<<endl;
}
//替换
void test02(){
    string s1="abcdef";
    //将从下标1处的开始的3个字符替换成"1111"
    s1.replace(1,3,"1111");
    cout<<"s1 = "<<s1<<endl;
}

int main(){
    test01();
    test02();
}