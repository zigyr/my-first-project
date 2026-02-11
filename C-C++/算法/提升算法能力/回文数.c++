//输入一个数字
//将这个数字与它反转过来的数字相加直至出现回文数
//统计相加次数并记录每次的结果输出
#include <iostream>
using namespace std;

int judge(int x){
    int tmp=x;
    int num[100];
    int cou=0;
    while(tmp){
        num[cou++]=tmp%10;
        tmp/=10;
    }
    for(int i=0;i<cou;i++){
        if(num[i]!=num[cou-1-i])return false;
    }
    return true;
}
int rve(int x){
    int res=0;
    while(x){
        //这里的算法思路也很厉害
        res=res*10+x%10;
        x/=10;
    }
    return res;
}

int main (){
    int x;
    cin>>x;
    int res=0;
    int num[100];
    num[res++]=x;
    while(!judge(x)){
        x+=rve(x);
        num[res++]=x;
    }
    cout<<res-1<<endl;
    for(int i=0;i<res;i++){
        if(i>0)cout<<"--->";
        cout<<num[i];
    }
}