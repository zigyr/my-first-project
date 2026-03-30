/*
4 4
2 1
3 2
1 3
2 4
-> 2
-> 1
-> 3
-> 2
-> 4
*/
#include <iostream>
using namespace std;;
#include <cstring>
#include <stack>

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
// degree 用来记录每个节点的入度与出度的差值
int degree[maxn];

int euler(){
    int first = 0, last = 0;
    for (int i = 1; i <= n; i++){
        if (degree[i] < -1 || degree[i] > 1){
            return -1;
        } else if (degree[i] == -1){
            if (first != 0){
                return 0;
            } else{
                first = i;
            }
        } else if (degree[i] == 1){
            if (last != 0){
                return 0;
            } else {
                last = i;
            }
        }
    }
    if (first == 0 && last == 0){
        return 1;
    } else if (first != 0 && last != 0){
        return first;
    } else {
        return 0;
    }
}

stack<int> path;
void dfs(int u){
    while(p[u] != -1){
        int v = e[p[u]].v;
        p[u] = e[p[u]].next;
        dfs(v);
    }
    path.push(u);
}

bool euler_find(){
    int start = euler();
    if (start == 0) return false;
    else{
        dfs(start);
        return (path.size() == m + 1);
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
        degree[u]--;
        degree[v]++;
    }
    if (!euler_find()){
        cout << "It doesn't have an euler path!" << endl;
    } else {
        while(!path.empty()){
            cout << path.top() << endl;
            path.pop();
        }
    }
}