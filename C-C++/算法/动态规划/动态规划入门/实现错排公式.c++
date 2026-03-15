/*
f[n] = (f[n-1] + f[n-2]) * (n-1)
*/
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e3;
#include <cstring>

int main (){
    int n;
    cin >> n;
    // method-one:
    ll f[N];
    memset(f, 0, sizeof(f));
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n; i++){
        f[i] = (f[i - 1] + f[i - 2]) * (i - 1);
    }
    cout << f[n] << endl;

    // method-two:
    ll a = 0, b = 1, c;
    for (int i = 3; i <= n; i++){
        c = (a + b) * (i - 1);
        a = b;
        b = c;
    }
    if (n == 1){
        cout << 0 << endl;
    } else if (n == 2){
        cout << 1 << endl;
    } else{
        cout << c << endl;
    }
}