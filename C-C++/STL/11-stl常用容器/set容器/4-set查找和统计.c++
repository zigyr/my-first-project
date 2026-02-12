#include <iostream>
#include <set>
using namespace std;

void test01(){
    set<int>s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    set<int>::iterator pos=s1.find(30);
    if(pos!=s1.end()){
        cout<<"exist"<<endl;
        cout<<*pos<<endl;
    }else{
        cout<<"unexist"<<endl;
    }

    //对于set而言，要么是0、要么是1
    int num=s1.count(30);
    cout<<"num="<<num<<endl;

}

int main (){
    test01();
}