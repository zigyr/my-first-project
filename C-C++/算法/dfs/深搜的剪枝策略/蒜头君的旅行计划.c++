/*
4
0 1 1 1   第一个数字表示一号城市到一号城市
1 0 2 1   第一个数字表示二号城市到一号城市
5 5 0 6
1 1 3 0
-> 8
先输入一个整数 n
接下来的 n x n 的矩形，
表示每两个城市之间的火车花费，不会超过 10000
输出一个整数，
表示从1号城市把所有景点旅游一遍并且返回1号城市的最小花费
*/

#include <iostream>
using namespace std;
#include <climits>
int ans = INT_MAX;
int n, st[10][10];
bool vis[10];
void dfs(int u, int cnt, int sum){
    if (sum > ans){
        return;
    }
    if (cnt == n){
        ans = min(ans, sum + st[u][1]);
        return;
    }
    vis[u] = true;
    for (int i = 1; i <= n ; i++){
        if (!vis[i]){
            dfs(i, cnt + 1, sum + st[u][i]);
        }
    }
    vis[u] = false;
}
int main (){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <=n; j++){
            cin >> st[i][j];
        }
    }
    dfs(1, 1, 0);
    cout << ans << endl;
}