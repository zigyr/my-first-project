#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myPrint(int val){
    cout<<val<<" ";
}

void demo1(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;

    reverse(v.begin(),v.end());

    for_each(v.begin(),v.end(),myPrint);
    cout<<endl;
}

int main (){
    demo1();
}