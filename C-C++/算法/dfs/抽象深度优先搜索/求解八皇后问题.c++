/*
在一个8 X 8的棋盘上放置8个皇后，
每行刚好放置一个并使其不能互相攻击(同一行、同一列、同一斜线上的皇后都会自动攻击)
计算一共有多少中合法的方法放置8个皇后
*/
#include <iostream>
using namespace std;
int ans;
int col[10], x1[20], x2[20];
bool check (int r, int i){
    return !col[i] && !x1[r + i] && !x2[r - i + 8];
}
void dfs (int r){
    if (r == 8){
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++){
        if (check(r, i)){
            col[i] = x1[r + i] = x2[r - i + 8] = true;
            dfs(r + 1);
            col[i] = x1[r + i] = x2[r - i + 8] = false;
        }
    }
}
int main (){
    dfs(0);
    cout << ans << endl;
}