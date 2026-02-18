/*
5 6
.#....
..#...
..#..#
...##.
.#....
#号代表草地，连在一起的草地叫做草丛，统计草丛的个数
*/
#include <iostream>
using namespace std;
#include <string>
int vis[105][105];
string mp[105];
int n,m;
int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
void dfs (int x,int y){
    // 法二：
    mp[x][y] = '.';
    for (int i = 0; i < 4; i++){
        int tx = x + dirs[i][0];
        int ty = y + dirs[i][1];
        if ((tx < n && tx >= 0 && ty < m && ty >= 0) &&  mp[tx][ty] == '#'){
            dfs(tx, ty);
        }
    }
    // // 法一：
    // if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || mp[x][y] == '.'){
    //     return;
    // }
    // vis[x][y] = 1;
    // dfs(x-1, y);
    // dfs(x+1, y);
    // dfs(x, y+1);
    // dfs(x, y-1);
}
int main (){
    int cou = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> mp[i];
    }
    // 通过dfs给连在一起的草地通过记忆化搜索打上标签
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!vis[i][j] && mp[i][j] == '#'){
                dfs(i,j);
                cou++;
            }
        }
    }
    cout << cou << endl;
}