/*
5 5
0 0 0 1 0
0 0 0 1 0
0 1 0 0 1
1 0 0 0 1
0 1 0 0 0
-> 2
*/
#include <iostream>
using namespace std;
int n, m, ans;
int mp[1005][1005];
void dfs(int x, int y){
    mp[x][y] = 0;
    for (int i = 0; i < n; i++){
        if (mp[i][y] == 1){
            dfs(i, y);
        }
    }
    for (int i = 0; i < m; i++){
        if (mp[x][i] == 1){
            dfs(x, i);
        }
    }
}
int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mp[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mp[i][j] == 1){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
}