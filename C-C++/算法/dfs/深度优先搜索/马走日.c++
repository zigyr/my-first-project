/*
再nXm的棋盘上，从S出发，看是否能到达T
马走日
.为通路
#为障碍
S为起点，T为终点
*/
#include <iostream>
using namespace std;

const int n = 10, m = 9;
string maze[n];
int vis[n][n];
int dir[8][2] = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2},
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};
bool f;

bool in(int x,int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x,int y){
    // 剪枝
    if (f)
        return;
    if (maze[x][y] == 'T'){
        f = true;
        return;
    }

    vis[x][y] = true;

    for (int i = 0; i < 8; i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] != '#')
            dfs(tx, ty);
    }
}
int main (){
    for (int i = 0; i < n; i++){
        cin >> maze[i];
    }

    int x, y;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (maze[i][j] == 'S'){
                x = i, y = j;
                break;
            }
        }
    }

    dfs(x, y);
    if (f) 
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}