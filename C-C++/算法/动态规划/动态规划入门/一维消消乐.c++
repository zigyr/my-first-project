/*
有 n 颗珠子排成一排, 每一颗珠子的价值为 wi（可能为负数）
游戏规则如下：
    每次选择若干相邻的柱珠子，让他们同时消去，
    每一对珠子的消失，
    都会使得总分数加上两颗珠子相乘的分数
    每个珠子只能消去一次, 且消去后仍然占位
求解最大分数
8
-9 -5 -4 -2 4 -5 -4 2
-> 73
*/
#include <iostream>
using namespace std;

const int maxn = 1010;

int w[maxn], dp[maxn][2];
// 1 代表和前面组合
// 0 代表未和前面组合

int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 2; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + w[i] * w[i - 1];
    }
    cout << max(dp[n][0], dp[n][1]);
}