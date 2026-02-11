/*
买了一堆桃子
每天吃剩下桃子的一般还多一个
到第n天只剩下一个桃子了
问一开始买了多少桃子
*/
#include <cstdio>
int n;
int f(int x){
    if(x==n){
        return 1;
    }
    //返回第1天的桃子数
    //其实就是在假设第2天的桃子数已知的情况下做运算
    return (f(x+1)+1)*2;
}
int main (){
    scanf("%d",&n);
    printf("%d",f(1));
}