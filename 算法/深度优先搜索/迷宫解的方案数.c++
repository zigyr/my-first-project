/*
5 5
S####
.####
.####
.####
....e
*/
#include <iostream>
using namespace std;
#include <string>
int n, m, ans;
bool vis[15][15];
string maze[15];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool in (int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}
void dfs (int x, int y){
    if (in(x, y) || vis[x][y] || maze[x][y] == '#'){
        return;
    }
    if (maze[x][y] == 'e'){
        ans++;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        dfs(tx, ty);
    }
    vis[x][y] = false;
}
int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> maze[i];
    }
    int x,y;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (maze[i][j] == 'S'){
                x = i, y = j;
                break;
            }
        }
    }
    dfs(x, y);
    cout << ans << endl;
}