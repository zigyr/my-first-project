/*
N 个物品,
第 i 个物品的体积是 ci, 价值是 wi, 数量是 无限,
现容量为 V 的背包,
在总体积不超过 V 的前提下, 价值最大

dp[i][j]表示:
    只考虑前 i 个物品,
    背包容量为 j 时,
    能装下的最大值

5 10
2 1
3 5
2 5
3 4
4 3
-> 20
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn];
int w[maxn], c[maxn];

int main (){
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; i++){
        cin >> w[i] >> c[i];
    }
    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= V; j++){
            if (j >= c[i]){
                dp[i][j] = max(dp[i][j - c[i]] + w[i], dp[i - 1][j]);
            } else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][V] << endl;
}