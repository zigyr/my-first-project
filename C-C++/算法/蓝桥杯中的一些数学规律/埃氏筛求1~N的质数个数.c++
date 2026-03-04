#include <iostream>
using namespace std;

int primes[1000];
bool st[1000];

int sieve(int n){
    int cnt = 0;
    for (int i = 2; i <= n; i++){
        if (!st[i]){
            primes[cnt++] = i;
            for (int j = i * i; j <= n; j += i){
                // 当处理到质数 i 时，
                // 所有小于 i*i 的 i 的倍数（即 i*2, i*3, ..., i*(i-1)），
                // 其实已经被更小的质数筛掉了。
                // 因此，
                // 我们可以直接从 i*i 开始标记，
                // 从而减少不必要的操作，提升效率
                st[j] = true;
            }
        }
    }
    return cnt;
}

int main (){
    int n;
    cin >> n;
    cout << sieve(n) << endl;
    for (int i = 0; i < sieve(n); i++){
        cout << primes[i] << " ";
    }
}