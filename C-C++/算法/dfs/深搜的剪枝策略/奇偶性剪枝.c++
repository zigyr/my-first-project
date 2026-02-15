/*
4 4 5
S.X.
..X.
..XD
....
-> NO
'S' 为起点
'D' 为终点
'X' 为墙壁
'.' 为平地
每次移动消耗1时间
已知出口的大门会在T时间打开
判断在0时间从起点出发是否能逃离迷宫
*/
#include <iostream>
using namespace std;
int n, m, t;
char mp[10][10];
bool flag, vis[10][10];
int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
void dfs(int x, int y, int t){
    if (flag) return;
    if (x == n){
        if (mp[x][y] == 'D') flag = true;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++){
        int tx = x + dirs[i][0];
        int ty = y + dirs[i][1];
        if (vis[tx][ty] || tx < 0 || tx >= n || ty < 0 || ty >= m || mp[tx][ty] == 'X')
            continue;
        dfs(tx, ty, t + 1);
    }
    vis[x][y] = false;
}
int main (){
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mp[i][j];
        }
    }
    int ex, ey, sx, sy;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == 'S') sx = i, sy = j;
            if (mp[i][j] == 'D') ex = i, ey = j;
        }
    }
    dfs(sx, sy, 0);
    if ((ex + ey + sx + sy + t) % 2 != 0){
        cout << "NO" << endl;
    } else {
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}