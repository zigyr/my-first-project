/*
第一行输入两个数字, 代表棋盘的行数和列数
第二行输入两个数字, 代表马的初始位置
输出整个棋盘
. 代表棋盘上可以落子的点
# 代表马走三步能到达的点
*/
#include <iostream>
using namespace std;
char mp[100][100];
int n, m;
int dir[8][2] = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2},
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};
void dfs(int x, int y, int step){
    if (step > 3){
        return;
    }
    if (x < 0 || x >= n || y < 0 || y >= m){
        return;
    }
    // 对应数组下标
    mp[x][y] = '#';
    for (int i = 0; i < 8; i++){
        dfs(x + dir[i][0], y + dir[i][1], step + 1);
    }
}
int main (){
    int x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mp[i][j] = '.';
        }
    }
    // 对应数组下标
    dfs(x - 1, y - 1, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mp[i][j];
        }
        cout << endl;
    }
}