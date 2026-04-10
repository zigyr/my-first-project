/*
30 8 200
-> 70
*/
// 这个方法比法一玄妙
// 多品
#include <iostream>
using namespace std;

int a[100];
bool vis[100];
int n, k, sum;
int ans;

void dfs(int pos, int c, int s){
    if (c > k || s > sum)
        return;
    
    if (c == k && s == sum){
        ans++;
        return;
    }

    for (int i = pos; i <= n; i++){
        if (!vis[i]){
            vis[i] = true;
            dfs(i + 1, c + 1, s + a[i]);
            vis[i] = false;
        }
    }
}

int main (){
    cin >> n >> k >> sum;
    for (int i = 1; i <= n; i++){
        a[i] = i;
    }
    
    dfs(1, 0, 0);
    cout << ans << endl;
}