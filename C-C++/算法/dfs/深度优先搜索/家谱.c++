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

int ans[1010];
vector<int> son[1010];
bool flag[1010];
int n;
bool vis[1010];

int dfs(int u){
    int ret = 0;

    for (int i = 0; i < son[u].size(); i++)
        ret += dfs(son[u][i]);

    ans[u] = ret;
    return ret + 1;
}

int main (){
    cin  >> n;
    for (int i = 0; i < n - 1; i++){
        int n1, n2;
        cin >> n1 >> n2;
        son[n1].push_back(n2);
        flag[n2] = true;
    }

    // 寻找起始点
    // 即没有父系的老祖
    int u;
    for (int i = 1; i <= n; i++){
        if (!flag[i]){
            u = i;
            break;
        }
    }

    dfs(u);
    for (int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
}