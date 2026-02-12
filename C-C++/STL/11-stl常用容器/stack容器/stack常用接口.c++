#include <iostream>
#include <stack>
using namespace std;

void test01(){
    stack<int>s;

    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    while(!s.empty()){
        cout<<"this top of the stack is:"<<s.top()<<endl;
        s.pop();
    }

    cout<<"the size of this stack is:"<<s.size()<<endl;
}

int main (){
    test01();
}