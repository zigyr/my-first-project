#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v){
    for(const auto& a:v){
        cout<<a<<" ";
    }
    cout<<endl;
}

void test01(){
    vector<int>v1;

    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    printVector(v1);

    //尾删
    v1.pop_back();
    printVector(v1);

    //插入
    //第一个参数是位置迭代器，第二个是应插入元素
    v1.insert(v1.begin(),100);
    printVector(v1);
    //第一个参数是位置迭代器，第二个参数是第三个应插入元素的个数
    v1.insert(v1.begin(),2,1000);
    printVector(v1);

    //删除
    v1.erase(v1.begin());
    printVector(v1);
    //清空容器操作
    // v1.erase(v1.begin(),v1.end());
    v1.clear();
    printVector(v1);
}

int main (){
    test01();
}