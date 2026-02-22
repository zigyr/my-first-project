/*
3
-> 2
输入一个整数 n
从 n x n 矩阵的左上方遍历所有点到左下方的路径数
*/
#include <iostream>
using namespace std;

bool vis[10][10];
int last[10][10];
int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, ans;

bool in(int x, int y){
    return x >=1 && x <= n && y >= 1 && y <= n;
}
void dfs(int x, int y, int cnt){
    if (x == n && y == 1){
        if (cnt == n * n){
            ans++;
        }
        return;
    }
    int dir = -1;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++){
        int ex = x + dirs[i][0];
        int ey = y + dirs[i][1];
        if (in(ex, ey) && !vis[ex][ey]){
            last[ex][ey]--;
            if (last[ex][ey] == 1){
                dir = i;
                // 当发现(x, y)的邻居(ex, ey)只剩下 1 条路能走了
                // 意味着, 必须选择它, 否则下次就不可能了
            }
        }
    }
    for (int i = 0; i < 4; i++){
        if (dir != -1 && dir != i) continue;
        // 如果已经指定了某个必须走的方向
        // 那不是这个方向的路, 全部跳过、不走
        int tx = x + dirs[i][0];
        int ty = y + dirs[i][1];
        if (in(tx, ty) && !vis[tx][ty]){
            int ok = true;
            int r = 0;
            for (int j = 0; j < 4; j++){
                int ex = tx + dirs[j][0];
                int ey = ty + dirs[j][1];
                if (in(ex, ey) && !vis[ex][ey]){
                    if (last[ex][ey] < 2){
                        ok =false;
                        break;
                    } else if (last[ex][ey] == 2){
                        r++;
                    }
                }
            }
            if (ok && r <= 1) dfs(tx, ty, cnt + 1);
            // 如果有多个(tx, ty)的邻居(ex, ey)是理想的 last[ex][ey] == 2 的情况
            // 那必须pass
            // 因为, 只要选择其中一条, 那就意味着另一条将成死胡同
        }
    }
    vis[x][y] = false;
    for (int i = 0; i < 4; i++){
        int ex = x + dirs[i][0];
        int ey = y + dirs[i][1];
        if (in(ex, ey) && !vis[ex][ey]){
            last[ex][ey]++;
        }
    }
    // 把 last 数组回复到进入这个dfs之气的状态
    // 与前面 31 行对应
}

int main (){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 0; k < 4; k++){
                int tx = i + dirs[k][0];
                int ty = j + dirs[k][1];
                if (in(tx, ty)){
                    last[i][j]++;
                }
            }
        }
    }
    last[n][1]++;
    ans = 0;
    dfs(1, 1, 1);
    cout << ans << endl;
}