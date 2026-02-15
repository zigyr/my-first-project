/*
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
-> 2
*/
#include <iostream>
using namespace std;
int n, ans;
int mp[105][105];
int vy[105], vd1[105], vd2[105];

void dfs(int x, int p){
    if (x == n && p == 1){
        ans++;
        return;
    }
    if (x == n){
        dfs(0, 1);
        return;
    }
    // 注意这里的p是如何玩的
    for (int i = 0; i < n; i++){
        if (mp[x][i] && vy[i] != 3 && vy[i] != p && vd1[x + i] != 3 && vd1[x + i] != p && vd2[x - i + n] !=3 && vd2[x - i + n] !=p){
            // mp[x][i] 二重预警
            mp[x][i] = 0;
            vy[i] += p;
            vd1[x + i] += p;
            vd2[x - i + n] += p;
            dfs(x + 1, p);
            mp[x][i] = 1;
            vy[i] -= p;
            vd1[x + i] -= p;
            vd2[x - i + n] -= p;
        }
    }
    
}

int main (){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mp[i][j];
        }
    }
    dfs(0, 1);
    cout << ans << endl;
}