/*
5 5
0 0 0 1 0
0 0 0 1 0
0 1 0 0 1
1 0 0 0 1
0 1 0 0 0
-> 2
这道题根本不需要任何 “最优策略”
也不用选哪里引爆更划算
你随便挑一个没炸过的炸弹点一下
结果都是一样的
*/
#include <iostream>
using namespace std;

int n, m;
int maze[1010][1010];

void dfs(int x, int y){
    maze[x][y] = 0;

    // 行
    for (int i = 0; i < n; i++){
        if (maze[i][y])
            dfs(i, y);
    }
    // 列
    for (int i = 0; i < m; i++){
        if (maze[x][i])
            dfs(x, i);
    }
}

int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (maze[i][j]){
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;
}