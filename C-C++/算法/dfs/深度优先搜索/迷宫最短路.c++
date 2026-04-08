/*
入门-变形
3 4
S**.
....
***T
-> 5
*/
#include <iostream>
#include <string>
using namespace std;
int n,m;
int ans = 0x3f3f3f3f;
bool vis[105][105];
string maze[105];
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x,int y,int step){
    if (maze[x][y] == 'T'){
        ans = min(ans, step);
        return;
    }

    vis[x][y] = true;

    for (int i = 0; i < 4; i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];

        if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] != '*')
            dfs(tx, ty, step + 1);
    }

    vis[x][y] = false;
}

int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> maze[i];
    
    int x, y;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (maze[i][j] == 'S'){
                x = i, y = j;
                break;
            }
        }
    }

    dfs(x, y, 0);
    cout << ans << endl;
}