/*
完全背包问题

将正整数n表示成一系列正整数之和:
n = n1 + n2 + n3 + ^^^ + nk,
其中n1 > n2 > n3 > ^^^ > nk
正整数n的这种表示称作正整数n的划分
求正整数n的不同划分个数

dp[j] 表示用不大于i的数凑出j的方案数
状态转移方程: dp[j] = dp[j] + dp[j - i]
                     保 留    选    择

1
6
-> 11
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn];
const int mod = 1e9 + 9;

int main (){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j++){
                (dp[j] += dp[j - i]) % mod;
            }
        }
        /*
        n = 3
        i = 1:
            dp[1] = dp[1] + dp[0] = 1;
            dp[2] = dp[2] + dp[1] = 1;
            dp[3] = dp[3] + dp[2] = 1;
        i = 2:
            dp[2] = dp[2] + dp[0] = 2;
            dp[3] = dp[3] + dp[1] = 2;
        i = 3:
            dp[3] = dp[3] + dp[0] = 3;
        */


        cout << dp[n] << endl;
    }

}