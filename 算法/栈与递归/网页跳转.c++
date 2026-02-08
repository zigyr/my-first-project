/*
输入一个数字，代表操作次数
每次操作分为 打开页面 回退 前进
打开页面 VISIT 网址
回退     BACK
前进     FORWARD
如果每次操作成功，输出此次操作之后的网址，否则输出“Ignore”
*/
#include <iostream>
#include <stack>
using namespace std;
stack<string> s1,s2;
int main (){
    int n;
    cin>>n;
    string op,add;
    while(n--){
        cin>>op;
        //整体逻辑大差不差
        //分别对s1、s2进行操作，与判断
        if(op[0]=='V'){
            cin>>add;
            s1.push(add);
            //前进历史s2 后退历史s1是互斥的
            //当访问新的页面后，必须清空s2
            //例如A->B->C->D
            //当倒退的C，并访问了E网站时，访问路径就变成A->B->C->E
            //D就被忽略了
            while(!s2.empty()){
                s2.pop();
            }
        }else if(op[0]=='B'){
            if(s1.size() <= 1){
                cout<<"Ignore"<<endl;
                continue;
            }
            s2.push(s1.top());
            s1.pop();
        }else{
            if(s2.empty()){
                cout<<"Ignore"<<endl;
                continue;
            }
            s1.push(s2.top());
            s2.pop();
        }
        cout<<s1.top()<<endl;
    }
}