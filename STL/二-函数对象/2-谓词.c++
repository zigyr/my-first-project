#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//仿函数 返回值类型是bool数据类型，称为谓词

//一元谓词
class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};
void test01(){
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    //查找容器中 有没有大于5的元素
    vector<int>::iterator pos=find_if(v.begin(),v.end(),GreaterFive());
    if(pos==v.end()){
        cout<<"unexist"<<endl;
    }else{
        cout<<"exist:"<<*pos<<endl;
    }
}

//二元谓词
class MyCompare{
public:
    bool operator()(int v1,int v2){
        //降序
        return v1>v2;
    }
};
void test02(){
    vector<int>v2;
    v2.push_back(10);
    v2.push_back(40);
    v2.push_back(20);
    v2.push_back(50);
    v2.push_back(30);
    //默认升序
    sort(v2.begin(),v2.end());
    for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"after sorted again by against"<<endl;
    //自定义降序
    sort(v2.begin(),v2.end(),MyCompare());
    for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main (){
    test01();
    test02();
}