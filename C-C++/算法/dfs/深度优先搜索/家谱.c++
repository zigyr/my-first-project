/*
4
1 2
1 3
2 4
->3
->1
->0
->0
*/
#include <iostream>
using namespace std;
#include <vector>
vector<int> son[1005];
bool f[1005];
int n, ans[1005];
int dfs(int u){
    int ret = 0;
    for (int i = 0; i < son[u].size(); i++){
        ret += dfs(son[u][i]);
    }
    ans[u] = ret;
    return ret + 1;
}
int main (){
    cin >> n;
    int tmp1, tmp2;
    for (int i = 0; i < n - 1; i++){
        cin >> tmp1 >> tmp2;
        son[tmp1].push_back(tmp2);
        f[tmp2] = true;
    }
    int u;
    for (int i = 1; i <= n; i++){
        if (!f[i]) {
            u = i;
            break;
        }
    }
    dfs(u);
    for (int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
}