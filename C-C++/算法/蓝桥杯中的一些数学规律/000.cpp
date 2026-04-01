#include <iostream>
using namespace std;

int primes[1000];
bool vis[1000];

int sieve(int n){
    int cnt = 0;
    for (int i = 2; i <= n; i++){
        if (!vis[i]){
            primes[cnt++] = i;
            for (int j = i * i; j <= n; j += i) vis[j] = true;
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
    cout << endl;
}