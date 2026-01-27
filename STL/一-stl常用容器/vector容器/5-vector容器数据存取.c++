#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v){
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    
    //通过[]访问
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    //通过at访问
    for(int i=0;i<v1.size();i++){
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;

    //.front()
    cout<<"第一个元素为："<<v1.front()<<endl;
    //.back()
    cout<<"最后一个元素为："<<v1.back()<<endl;
}

int main (){
    test01();
}