#include <iostream>
#include <map>
using namespace std;

class Person{
public:
    bool operator()(int v1,int v2)const{
        //降序
        return v1>v2;
    }
};

void test01(){
    //map容器自动按照key值升序排序
    map<int,int>m1;

    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(5,50));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(4,40));

    for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++){
        cout<<"key= "<<(*it).first<<" value= "<<it->second<<endl;
    }
    cout<<endl;

    //自定义仿函数来实现降序排序
    map<int,int,Person>m2;

    m2.insert(make_pair(1,10));
    m2.insert(make_pair(3,30));
    m2.insert(map<int,int,Person>::value_type(5,50));
    m2.insert(make_pair(2,20));
    m2.insert(make_pair(4,40));

    //自动按照key值升序排序
    for(map<int,int,Person>::iterator it=m2.begin();it!=m2.end();it++){
        cout<<"key= "<<(*it).first<<" value= "<<it->second<<endl;
    }
    cout<<endl;



}

int main (){
    test01();
}