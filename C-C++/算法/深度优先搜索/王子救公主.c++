/*
第一行输入两个整数, 表示迷宫的行和列
然后输入一个 n X m 的地图
'.'表示可以通行的路, '#'表示迷宫中的墙, 'w' 表示王子开始所在的位置, 'g' 表示公主开始所在的位置
输出王子能否救出公主, yes or no
*/
#include <iostream>
using namespace std;
#include <string>
int n, m;
string mp[105];
bool vis[105][105][2];
void dfs(int x, int y, int d){
    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y][d] || mp[x][y] == '#'){
        return;
    }
    vis[x][y][d] = true;
    dfs(x + (2 - d), y, d);
    dfs(x - (2 - d), y, d);
    dfs(x, y + (2 - d), d);
    dfs(x, y - (2 - d), d);
}
int main (){
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> mp[i];
    }

    // 王子
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == 'w'){
                x = i, y = j;
                break;
            }
        }
    }
    dfs(x, y, 0);

    // 公主
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == 'g'){
                x = i, y = j;
                break;
            }
        }
    }
    dfs(x, y, 1);

    // 判断
    bool ans = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (vis[i][j][0] && vis[i][j][1]){
                ans = true;
                break;
            }
        }
    }
    if (ans){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}