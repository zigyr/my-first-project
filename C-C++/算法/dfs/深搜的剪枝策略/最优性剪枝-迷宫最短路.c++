/*
3 4
S**.
....
***T
-> 5
*/
#include <iostream>
#include <string>
#include <climits>
using namespace std;
int n, m;
int ans = INT_MAX;
bool vis[110][110];
string maze[110];
int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
void dfs(int x, int y, int step){
    if (step >= ans){
        return;
    }
    if (maze[x][y] == 'T'){
        if (step < ans) ans = step;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++){
        int tx = x + dirs[i][0];
        int ty = y + dirs[i][1];
        // 注意这里
        // 先判断坐标合法，再访问数组检验是否可通
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && maze[tx][ty] != '*' && !vis[tx][ty]){
            dfs(tx, ty, step + 1);
        }
    }
    vis[x][y] = false;
}
int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> maze[i];
    }
    int sx, sy;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (maze[i][j] == 'S'){
                sx = i, sy = j;
            }
        }
    }
    dfs(sx, sy, 0);
    cout << ans << endl;
}