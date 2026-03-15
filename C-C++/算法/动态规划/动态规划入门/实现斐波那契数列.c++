/*
输出第 n 个斐波那契数
*/
#include <iostream>
using namespace std;
const int N = 1e3;
typedef long long ll;
#include <cstring>

int main (){
    int n;
    cin >> n;
    // method-one
    ll f[N];
    memset(f, 0, sizeof(f));
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;

    // method-two
    ll a = 1, b = 1, c = 1; // c 的初始值, 与当n=1时的结果密切相关
    for (int i = 2; i <=n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    cout << c << endl;
}