/*
从n个不同元素中，任取k(k≤n)个元素并成一组
叫做从n个不同元素中取出k个元素的一个组合;
从n个不同元素中取出k(k≤n)个元素的所有组合的个数
叫做从n个不同元素中取出k个元素的组合数。
C(n, k) = n! / (k! * (n - k)!)  
          (n - k + 1) * (n - k + 2) * ... * (n - k + k)
        = ---------------------------------------------
               1      *      2      * ... *      k
        ==>  res = res * (n - k + i) / i;
*/
#include <iostream>
using namespace std;

typedef long long LL;

LL C(int n, int k){
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;

    // C(n, k) = C(n, n-k)
    if (k > n - k) k = n - k;

    LL res = 1;
    for (int i = 1; i <= k; i++){
        res = res * (n - k + i) / i;
    }
    return res;
}

int main (){   
    int n, k;
    cin >> n >> k;
    cout << C(n, k) << endl;
}