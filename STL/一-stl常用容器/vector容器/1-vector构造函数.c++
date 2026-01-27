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
    //一：默认无参构造
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    printVector(v1);

    //二：通过区间方式进行构造
    vector<int>v2(v1.begin(),v1.end());
    printVector(v2);

    //三：n个elem方式构造
    //初始v3为10个100
    vector<int>v3(10,100);
    printVector(v3);

    //四：拷贝构造(常用)
    vector<int>v4(v3);
    printVector(v4);
}

int main (){
    test01();
}