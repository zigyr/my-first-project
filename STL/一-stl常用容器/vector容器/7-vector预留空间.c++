#include <iostream>
#include <vector>
using namespace std;

void test01(){
    vector<int>v;

    //ÀûÓÃreserveÔ¤Áô¿Õ¼ä
    v.reserve(10000);
    
    int num=0;
    int *p=NULL;
    for(int i=0;i<10000;i++){
        v.push_back(i);
        if(p!=&v[0]){
            p=&v[0];
            num++;
        }
    }
    cout<<"num£º"<<num<<endl;

}

int main (){
    test01();
}