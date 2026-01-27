//输入两个数
//第一个即待转换数字
//第二个是几进制
#include <iostream>
using namespace std;
//注意数组类型
char ans[100];
int main (){
    int x,r;
    cin>>x>>r;
    int now;
    int m=0;
    while(x){
        now=x%r;
        if(now<=9){
            ans[m++]='0'+now;
            // cout<<(char)('0'+now)<<endl;
        }else{
            ans[m++]='A'+now-10;
            // cout<<(char)('A'+now-10)<<endl;
        }
        x/=r;
    }
    if(m==0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=m-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}