/*
30 8 200
-> 70
*/
#include <iostream>
using namespace std;
int n, k, sum, a[100], ans;
bool vis[100];
void dfs(int pos, int s, int c){
    if (s > sum || c > k) return; // 增添了一个出口
    if (s == sum && c == k){
        ans++;
    }
    for (int i = pos; i < n; i++){
        if (!vis[i]){
            vis[i] = true;
            dfs(i + 1, s + a[i], c + 1);
            vis[i] = false;
        }
    }
}
int main (){
    cin >> n >> k >> sum;
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    dfs(0, 0, 0);
    cout << ans << endl;
}