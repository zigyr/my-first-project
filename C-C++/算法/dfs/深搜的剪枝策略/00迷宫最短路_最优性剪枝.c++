/*
3 4
S**.
....
***T
-> 5
*/
#include <iostream>
#include <string>
using namespace std;

int n, m;
int ans = 0x3f3f3f3f;
bool vis[110][110];
string maze[110];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int step){
    if (step >= ans)
        return;

    if (maze[x][y] == 'T'){
        ans = min(ans, step);
        return;
    }

    vis[x][y] = true;
    for (int i = 0; i < 4; i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        /*先判断坐标合法, 在判断是否访问过、或是否可通*/
        if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] != '*')
            dfs(tx, ty, step + 1);
    }
    vis[x][y] = false;

}

int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> maze[i];
    }

    int x, y;
    for (int i = 0; i < n; i++){
        for (int j =0; j < m; j++){
            if (maze[i][j] == 'S')
                x = i, y = j;
        }
    }

    dfs(x, y, 0);
    cout << ans << endl;
}