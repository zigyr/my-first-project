/*
前两个参数定义地图大小
然两个参数定义其实位置（此时按照地图左上角下标(0,0)）
其次是初始血量, 最大血量
2 2 2 2 5 10
1 2
3 0
-> 9

3 3 3 3 5 20
3 0 0
3 0 0
3 3 0
-> 17

3 3 3 3 5 10
3 0 0
3 0 0
3 3 0
-> 13
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int a[maxn][maxn];
int dp[maxn][maxn];

int main (){
    int n, m, x, y, v, c;
    cin >> n >> m >> x >> y >> v >> c;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int dirs[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (int t = 0; t < 4; t++){
        for (int i = x; i > 0 && i <= n; i -= dirs[t][0]){
            for (int j = y; j > 0 && j <= m; j -= dirs[t][1]){
                if (i == x && j == y) dp[i][j] = v;
                else if (i == x) dp[i][j] = min(c, dp[i][j + dirs[t][0]]) + a[i][j];
                else if (j == y) dp[i][j] = min(c, dp[i + dirs[t][1]][j]) + a[i][j];
                else dp[i][j] = min(c, max(dp[i][j + dirs[t][0]], dp[i + dirs[t][1]][j])) + a[i][j];
                if (dp[i][j] <= 0) dp[i][j] = INT_MIN;
            }
        }
    }
    int ans = max(max(dp[1][1], dp[n][m]), max(dp[1][m], dp[n][1]));
    if (ans <= 0){
        cout << -1 << endl;
    } else{
        cout << ans << endl;
    }
}