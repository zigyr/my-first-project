#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
//查找相邻重复元素
void test01(){
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    // v.push_back(3);

    vector<int>::iterator pos=adjacent_find(v.begin(),v.end());
    if(pos==v.end()){
        cout<<"unexist"<<endl;
    }else{
        cout<<"find:"<<*pos<<endl;
    }
}

int main (){
    test01();
}