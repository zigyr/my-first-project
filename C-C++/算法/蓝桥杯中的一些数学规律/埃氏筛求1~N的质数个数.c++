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