#include <iostream>
using namespace std;
#include <string>

void test01(){
    string str="hello";

    //插入
    //在下标1处插入“111”字符串
    str.insert(1,"111");
    cout<<"str = "<<str<<endl;

    //删除
    //从下标1处开始产出3个字符
    str.erase(1,3);
    cout<<"str = "<<str<<endl;
}

int main (){
    test01();
}