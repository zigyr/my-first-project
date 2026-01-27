#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v){
    for(const auto& a:v){
        cout<<a<<" ";
    }
    cout<<endl;
}

//基本使用
//swap
void test01(){
    cout<<"交换前："<<endl;

    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    printVector(v1);

    vector<int>v2;
    for(int i=10;i>0;i--){
        v2.push_back(i);
    }
    printVector(v2);

    cout<<"交换后："<<endl;

    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//实际用途
//收缩内存空间
void test02(){
    vector<int>v;
    for(int i=0;i<10000;i++){
        v.push_back(i);
    }
    cout<<"容器v的容量为："<<v.capacity()<<endl;
    cout<<"容器v的大小为："<<v.size()<<endl;

    //重新指定大小
    v.resize(3);
    cout<<"容器v的容量为："<<v.capacity()<<endl;
    cout<<"容器v的大小为："<<v.size()<<endl;

    //巧用swap收缩内存空间
    vector<int>(v).swap(v);
    cout<<"容器v的容量为："<<v.capacity()<<endl;
    cout<<"容器v的大小为："<<v.size()<<endl;
}

int main (){
    // test01();
    test02();
}