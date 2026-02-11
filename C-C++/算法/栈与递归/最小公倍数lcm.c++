/*
lcm(a,b)=a*b/gcd(a,b)
*/
#include <iostream>
using namespace std;
// 递归函数
// if是预留递归出口
int gcd(int a,int b){
    if(b==0){
        return 0;
    }
    return gcd(b,a%b);
    // return b==0 ? a : gcd(b,a%b);
}
// 普通函数
// if用于检验数据合法性（0的参与没有意义）
int lcm(int a,int b){
    if(a==0||b==0){
        return 0;
    }
    return a*b/gcd(a,b);
    // return a==0||b==0 ? 0 : a*b/gcd(a,b);
}
int main (){
    int a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
}