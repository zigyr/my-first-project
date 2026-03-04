/*
卒从左上角(0, 0)位置向下或向右走向右下角终点(n, m)
同时, 地图中存在 马(cx, cy), 带上它所在位置, 马最多能控制 9 个格子
问卒在不经过这 9 个格子而到达终点的路径个数
5 5 2 4
-> 14
*/
#include <iostream>
using namespace std;

int dirs[8][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
bool d[30][30];
long long dp[30][30];

int main (){
    int n, m, cx, cy;
    cin >> n >> m >> cx >> cy;
    d[cx][cy] = true;
    for (int i = 0; i < 8; i++){
        int tx = cx + dirs[i][0];
        int ty = cy + dirs[i][1];
        if (tx >= 0 && tx <= n && ty >= 0 && ty <= m){
            d[tx][ty] = true;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (!d[i][j]){
                if (i){
                    dp[i][j] += dp[i - 1][j];
                }
                if (j){
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }
    cout << dp[n][m] << endl;
}