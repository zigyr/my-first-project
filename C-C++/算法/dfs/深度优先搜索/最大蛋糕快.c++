/*
同踏青, 不过计数逻辑不同, 稍稍有点难度
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

int res;
int n, m;
int cou;
string mp[1005];
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs (int x, int y){
    mp[x][y] = '.';
    cou++;

    for (int i = 0; i < 4; i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx, ty) && mp[tx][ty] == '#')
            dfs(tx, ty);
    }
}
int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> mp[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == '#'){
                cou = 0;
                dfs(i , j);
                res = max(res, cou);
            }
        }
    }
    
    cout << res << endl;
}