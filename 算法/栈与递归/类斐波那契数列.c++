/*
fn表示新数列的第n项
f1=f2=1, fn=a*fn-1 + b*fn-2(n>2)
输入4个整数，n、a、b、p
输出fn对p取模的值
*/
#include <cstdio>
int ans[200];
bool vis[200];
int f(int n,int a,int b,int p){
    //递归
    if(n==1||n==2){
        return 1%p;
    }else{
        return ( a*f(n-1,a,b,p)%p+b*f(n-2,a,b,p)%p )%p;
    }
    // //递归+记忆化搜索
    // if(vis[n]){
    //     return ans[n];
    // }
    // vis[n]=true;
    // if(n==1||n==2){
    //     return ans[n]=1%p;
    // }else{
    //     return ans[n]=( a*f(n-1,a,b,p)%p+b*f(n-2,a,b,p)%p )%p;
    // }
}
int main (){
    int n,a,b,p;
    scanf("%d %d %d %d",&n,&a,&b,&p);
    printf("%d",f(n,a,b,p));
}