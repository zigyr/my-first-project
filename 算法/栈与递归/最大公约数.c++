/*
f(x,y)={
    f(y,x%y) y>0
    x y=0
}
输入x，y，返回x，y的最大公约数
 */
#include <cstdio>
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main (){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",gcd(x,y));
    return 0;
}

