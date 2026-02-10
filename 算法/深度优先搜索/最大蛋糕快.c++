/*
5 6
.#....
..#...
..#..#
...##.
.#....
#为喜欢吃的水果，.为不喜欢吃的水果
要求切出的蛋糕只包含自己喜欢吃的水果，可以不为矩形，但必须是在网格中连通的
求解最大可以吃到多大的蛋糕
*/
#include <iostream>
using namespace std;
#include <string>
#include <climits>
int res = INT_MIN;
int n, m, cou;
string mp[1005];
bool vis[1005][1005];
void dfs (int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || mp[x][y] == '.'){
        return;
    }
    vis[x][y] = true;
    //注意cou的递增位置
    cou++;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> mp[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == '#' && !vis[i][j]){
                cou = 0;
                dfs(i , j);
                if(cou > res){
                    res = cou;
                }
            }
        }
    }
    cout << res << endl;
}