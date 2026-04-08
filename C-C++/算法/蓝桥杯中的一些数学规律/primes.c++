#include <iostream>
using namespace std;

int primes[1000]; // 存放质数的容器
bool st[1000];    // 1 - n 要遍历的数字
// 初始为false, 表示为非质数; 置为true, 即(st[i] = true)表示i为质数

int sieve(int n){
    int cnt = 0;
    for (int i = 2; i <= n; i++){
        if (!st[i]){
            primes[cnt++] = i;
            // 注意这里的 for循环 的循环因子是 (j += i)
            /*非常重要*/
            for (int j = i * i; j <= n; j += i) st[j] = true;
                // 当处理到质数 i 时，
                // 所有小于 i*i 的 i 的倍数（即 i*2, i*3, ..., i*(i-1)），
                // 其实已经被更小的质数筛掉了。
                // 因此，
                // 我们可以直接从 i*i 开始标记，
                // 从而减少不必要的操作，提升效率
        }
    }
    return cnt;
}

int main (){
    int n;
    cin >> n;
    int cnt = sieve(n);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++){
        cout << primes[i] << " ";
    }
}