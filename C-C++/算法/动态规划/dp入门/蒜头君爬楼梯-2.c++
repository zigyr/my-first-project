/*
初始在 楼底
一次只能爬 奇数个 阶梯
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
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        dp[i] = 0;
        for (int j = i - 1; j >= 0; j -= 2){
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << endl;
}