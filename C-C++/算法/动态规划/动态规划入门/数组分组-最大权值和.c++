/*
一个长度为 n 的数组
可以把它任分为任意组, 每一组是一段连续区间
每个分组都有一个权值, 这个权值是分组里面每个数的乘积对 1000 取模的结果
对于数组a的一个分组方案, 总权值就是每个分组的权值和
求解最大权值和
7
52 26 1 36 72 48 43
-> 1596
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
const int mod = 1000;

int pre[maxn][maxn], a[maxn], dp[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        pre[i][i] = a[i];
        for (int j = i + 1; j <= n; j++){
            pre[i][j] = pre[i][j - 1] * a[j] % mod;
        }
    }

    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++){
        // dp[i] 是指前 i 个数总成的数组的总权值和的最优解
        // j 表示 若干截断点
        for (int j = 0; j < i; j++){
            dp[i] = max(dp[i], dp[j] + pre[j + 1][i]);
            // 这里的max就是去判断循环遍历的截断点中是否出现最优解
        }
    }

    cout << dp[n] << endl;
}