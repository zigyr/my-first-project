#include <iostream>
#include <string>
using namespace std;

void test01(){
    //
    string str1="hello";
    str1+=", world!";
    cout<<"str1 = "<<str1<<endl;

    //
    string str2="hello";
    str2.append(", C++!");
    cout<<"str2 = "<<str2<<endl;

    //
    string str3;
    str3.append("game and abcde",9);
    cout<<"str3 = "<<str3<<endl;

    //
    string str4;
    str4.append(str2);
    cout<<"str4 = "<<str4<<endl;

    //
    string str5="";
    str5.append(str3,5,3);  
    cout<<"str5 = "<<str5<<endl;
}

int main (){
    test01();
}