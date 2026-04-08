/*
关于x**y，如果用for循环相乘，在y很大的情况下，浪费计算资源
优化后如下：
f(x,y)={
    f(x,y/2)*f(x,y/2)     y%2=0,y>0
    1                     y=0
    f(x,y/2)*f(x,y/2)*x   y%2=1,y>0
}
输出x**y % p
*/
#include <iostream>
using namespace std;

typedef long long LL;

const int mode = 1000;

LL my_pow(LL a, LL b){
    if (b == 0)
        return 1;
    
    if (b % 2 == 0 && b > 0)
        return my_pow(a, b / 2) * my_pow(a, b / 2) % mode;
    
    if (b % 2 == 1 && b > 0)
        return my_pow(a, b / 2) * my_pow(a, b / 2) * a % mode;
}

int main (){
    LL a, b;
    cin >> a >> b;
    cout << my_pow(a, b) << endl;
}