#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myPrint(int val){
    cout<<val<<" ";
}

class Greater6{
public:
    bool operator()(int val){
        return val>=6;
    }
};

void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
    
    //替换后：
    replace_if(v.begin(),v.end(),Greater6(),900);
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;

    
}

int main (){
    test01();
}