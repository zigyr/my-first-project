/*
蒜头君从 左上角 走到 右下角
格子上的数字, 代表该点需要消耗的体力
要求寻找一个消耗体力最少的路径, 并输出最小消耗体力
3
+-+-----+
| +1|2|3|
+-+-----+
|1|0|3|4|
+-+-----+
|2|6|2|5|
+-+-----+
|3|5|4|3|
+-------+
-> 12
雷同于马踏过河卒问题
*/
#include <iostream>
using namespace std;
#include <algorithm>
int a[110][110];
int dp[110][110];
int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    dp[1][1] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == 1 && j == 1){
                continue;
            } else if (i == 1){
                dp[i][j] = dp[i][j - 1] + a[i][j];
            } else if (j == 1){
                dp[i][j] = dp[i - 1][j] + a[i][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
    }
    cout << dp[n][n] << endl;
}