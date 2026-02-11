/*
火车出入站问题，也就是一个数组1--n依次进栈，判断其出栈的情况是否合法
输入：第一行输入一个整数n，代表火车车厢个数，虽可能是乱序，但整体编号是从1到n
     第二行输入n个数字，代表待判断的出栈情况
输出：如果合法，legal；否则，illegal
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main (){
    int n;
    cin>>n;
    int tmp;vector<int> a;
    for(int i=0;i<n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    int f=1;
    int cur=1;
    stack<int>s;
    for(int i=0;i<n;i++){
        while((s.empty()||s.top()!=a[i])&&cur<=n){
            s.push(cur);
            cur++;
        }
        if(s.empty()||s.top()!=a[i]){
            f=0;
            break;
        }else{
            s.pop();
        }
    }
    if(f){
        cout<<"legal"<<endl;
    }else{
        cout<<"illegal"<<endl;
    }
}