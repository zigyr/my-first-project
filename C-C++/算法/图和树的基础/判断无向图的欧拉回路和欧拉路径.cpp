/*
能不重复的遍历图中的所有边(欧拉图)
if(起点==终点)欧拉回路
else(起点!=终点)欧拉路径
*/
/*
欧拉回路：当且仅当图中恰有0个顶点的度数为奇数
欧拉路径：当且仅当图中恰有2个顶点的度数为奇数
*/
/*
4 4
1 2
3 2 
1 3
2 4
-> It have an euler path!
*/
#include <iostream>
using namespace std;;
#include <cstring>

const int maxn = 1000;

struct edge{
    int v, next;
} e[maxn << 1];

int p[maxn], eid;
void init(){
    memset(p, -1, sizeof(p));
    eid = 0;
}

void insert(int u, int v){
    e[eid].v = v;
    e[eid].next = p[u];
    p[u] = eid++;
}


int n, m;
int degree[maxn];

int cnt;
bool vis[maxn];
void dfs(int u){
    vis[u] = true;
    cnt++;
    for (int i = p[u]; ~i; i = e[i].next){
        int v = e[i].v;
        if (!vis[v]) dfs(v);
    }
}
void euler(){
    dfs(1);
    if (cnt != n){
        cout << "It doesn't have an euler path!" << endl;
        return;
    }
    int cntodd = 0;
    for (int i = 1; i <= n; i++){
        if (degree[i] % 2){
            cntodd++;
        }
    }
    if (cntodd == 0){
        cout << "It have an euler circuit!" << endl;
        return;
    } else if (cntodd == 2){
        cout << "It have an euler path!" << endl;
        return;
    } else{
        cout << "It doesn't have an euler path!" << endl;
        return;
    }
}

int main(){
    init();
    memset(degree, 0, sizeof(degree));
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
        degree[u]++;
        degree[v]++;
    }
    euler();
}