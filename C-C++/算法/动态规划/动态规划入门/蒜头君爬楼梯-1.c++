/*
初始在 楼底
一次只能爬 1个 或 2个阶梯
对于一共有 n阶 的楼梯
问一共有多少种方法从楼底到楼顶
*/

#include <iostream>
using namespace std;

const int mod = 100007;
int dp[1010];

int main (){
    int n;
    cin >> n;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    cout << dp[n] << endl;
}