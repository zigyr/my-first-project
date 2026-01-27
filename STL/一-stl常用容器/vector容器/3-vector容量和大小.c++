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
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    printVector(v1);

    //Ϊ�棬��������Ϊ��
    if(v1.empty()){
        cout<<"����Ϊ��"<<endl;
    }else{
        cout<<"������Ϊ��";
        cout<<"����Ϊ"<<v1.capacity()<<endl;
        cout<<"��СΪ"<<v1.size()<<endl;
    }

    //����ָ��������С
    //���ָ����С���ڵ�ǰ������С������ಿ��Ĭ����0���
    //�������ָ����С��ԭ������С���������ֻᱻɾ��
    v1.resize(15,10);
    printVector(v1);

    v1.push_back(100);
    printVector(v1);

    
}

int main (){
    test01();
}