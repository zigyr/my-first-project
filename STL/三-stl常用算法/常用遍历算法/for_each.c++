#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//普通函数
void print01(int val){
    cout<<val<<" ";
}
void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
}

//仿函数
class print02{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
void test02(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print02());
    cout<<endl;
}

//lambda
void test03(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),[](int x){
        cout<<x<<" ";
    });
    cout<<endl;
}

int main (){
    // test01();
    // test02();
    test03();
}