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