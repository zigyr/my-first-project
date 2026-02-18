/*
3
-> 6
-> 123
-> 132
-> 213
-> 231
-> 312
-> 321
*/
#include <iostream>
using namespace std;
int n;
bool vis[100];
void dfs(int s, int cnt){
    if (cnt == n){
        cout << s << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            vis[i] = true;
            dfs(s * 10 + i, cnt + 1);
            vis[i] = false;
        }
    }
}
int main (){
    cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; i++){
        ans *= i;
    }
    cout << ans << endl;
    dfs(0, 0);
}