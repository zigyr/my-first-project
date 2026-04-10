/*
4 4 5
S.X.
..X.
..XD
....
-> NO
'S' 为起点
'D' 为终点
'X' 为墙壁
'.' 为平地
每次移动消耗1时间
已知出口的大门会在T时间打开
必须刚好在第 t 秒的时候，站在 D 的位置，才能逃出去
早到、晚到、走不到，都算失败，输出 NO
*/
#include <iostream>
using namespace std;
int n, m, t;
char mp[10][10];
bool flag, vis[10][10];
int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int ex, ey;
void dfs(int x, int y, int t){
    if (flag) 
        return;
    /*
    :: 叫 作用域解析符(C++专属)
    ::t = 全局变量的 t
    不加 :: 的 t = 函数里的局部变量 t
    */
    if (x == ex && y == ey && t == ::t){
        flag = true;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++){
        int tx = x + dirs[i][0];
        int ty = y + dirs[i][1];
        if (in(tx, ty) && !vis[tx][ty] && mp[tx][ty] != 'X')
            dfs(tx, ty, t + 1);
            
    }
    vis[x][y] = false;
}
int main (){
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];
    }

    int sx, sy;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == 'S') sx = i, sy = j;
            if (mp[i][j] == 'D') ex = i, ey = j;
        }
    }

    /*
    最短距离是 奇数 → 无论怎么绕路，总步数永远是 奇数
    最短距离是 偶数 → 无论怎么绕路，总步数永远是 偶数
    由于题目要求 必须刚好在 T 步（时间）到达终点
    要想刚好 T 步到达终点，T 的奇偶性，必须等于所有合法路径的共同奇偶性（也就是最短路径 d 的奇偶性）
    */
    if ((ex + ey + sx + sy + t) & 1)
        cout << "NO" << endl;
    else {
        dfs(sx, sy, 0);
        if (flag) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}