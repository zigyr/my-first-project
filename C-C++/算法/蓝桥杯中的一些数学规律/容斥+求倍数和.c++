/*
在 1 ~ 100 的整数里
是 3 的倍数 或者 5 的倍数的数
他们的总数和是多少
*/

#include <iostream>
using namespace std;

typedef long long LL;

LL sum(LL k){
    return (1 + k) * k / 2;
}

int main (){
    int a = 100;
    int x = 3, y = 5, z = x * y;
    LL ans = x * sum(a/x) + y * sum(a/y) - z * sum(a/z);
    // 求解 1~n 以内的 a 的倍数的和
    // a * sum(n / a)
    cout << ans << endl; 
}