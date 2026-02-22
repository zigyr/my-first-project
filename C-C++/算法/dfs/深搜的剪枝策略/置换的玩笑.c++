/*
4111109876532
-> 4 1 11 10 9 8 7 6 5 3 2
将输入的数据复原, 数据不重复
*/
#include <iostream>
using namespace std;
string s;
int ans[100];
int n;
bool vis[100];
bool ok;

void dfs(int u, int cnt){
    if (ok) return;
    if (u == s.size()){
        for (int i = 0; i < cnt; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        ok = true;
        return;
    }
    
    int x = s[u] - '0';
    if (x <= n && !vis[x]){
        ans[cnt] = x;
        vis[x] = true;
        dfs(u + 1, cnt + 1);
        vis[x] = false;
    }

    if (u + 1 >= s.size()) return;
    
    x = x * 10 + s[u + 1] - '0';
    if (x <= n && !vis[x]){
        ans[cnt] = x;
        vis[x] = true;
        dfs(u + 2, cnt + 1);
        vis[x] = false;
    }

}

int main (){
    cin >> s;
    n = s.size() <= 9 ? s.size() : (s.size() - 9) / 2 + 9;
    dfs(0, 0);
}