/*
关于x**y，如果用for循环相乘，在y很大的情况下，浪费计算资源
优化后如下：
f(x,y)={
    f(x,y/2)*f(x,y/2)   y%2=0,y>0
    1   y=0
    f(x,y/2)*f(x,y/2)*x    y%2=1,y>0
}
输出x**y % p
*/
#include <cstdio>
typedef long long ll;
ll f(ll x,ll y,ll p){
    if(y==0){
        return 1%p;
    }
    if(y%2==0){
        ll tmp=f(x,y/2,p);
        return tmp*tmp%p;
        // return f(x,y/2,p)*f(x,y/2,p)%p;
    }
    if(y%2==1){
        ll tmp=f(x,y/2,p);
        return tmp*tmp%p*x%p;
        // return f(x,y/2,p)*f(x,y/2,p)%p*x%p;
    }
}
int main (){
    ll x,y,p;
    scanf("%lld %lld %lld",&x,&y,&p);
    printf("%lld",f(x,y,p));
}