/*
关于这种根据马尔科夫链写的递归函数
其实可以将递归方程的等号看作是return
比如本题(猴子摘桃)、类斐波那契数列、快速幂

买了一堆桃子
每天吃剩下桃子的一般还多一个
到第n天只剩下一个桃子了
问一开始买了多少桃子
*/
#include <iostream>
using namespace std;

int n;

// f(d)表示第1天的时候的桃子数量
// 也就是总的桃子
/*
第x天  1    2    3    4   ... n
桃 子 f(1) f(2) f(3) f(4) ... 1

马尔科夫链：f(n + 1) = f(n) - f(n) / 2 - 1;
整  理  得： f(n) = (f(n + 1) + 1) * 2
即      有： f(n) return (f(n + 1) + 1) * 2
*/
int f(int d){
    if (d == n)
        return 1;
    return (f(d + 1) + 1) * 2; 
}

int main (){
    cin >> n;
    cout << f(1) << endl;
}