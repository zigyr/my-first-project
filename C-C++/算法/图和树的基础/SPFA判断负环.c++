/*
4 4
1 2 1
2 3 1
1 3 -3
3 4 1
-> yes
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e3 + 9;

struct edge{
    int v, w, fail;
    edge(){}
    edge(int _v, int _w, int _fail){
        v = _v;
        w = _w;
        fail = _fail;
    }
} e[N << 1];

int head[N], len;
void init(){
    memset(head, -1, sizeof head);
    len = 0;
}

void add(int u, int v, int w){
    e[len] = edge(v, w, head[u]);
    head[u] = len++;
}
void add2(int u, int v, int w){
    add(u, v, w);
    add(v, u, w);
}

int n, m;

int dis[N], in[N];
bool vis[N];
bool spfa(int u){
    memset(vis, false, sizeof(vis));
    vis[u] = true;
    memset(dis, 0x3f, sizeof(dis));
    dis[u] = 0;
    memset(in, 0, sizeof(in));
    in[u] = 1;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop(); vis[u] = false;
        for (int j = head[u]; ~j; j = e[j].fail){
            int v = e[j].v;
            int w = e[j].w;
            if (dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if (!vis[v]){
                    q.push(v);
                    vis[v] = true;
                    in[v]++;
                    if (in[v] > n) return true;
                }
            }
        }
    }
    return false;
}

int main (){
    init();
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        add2(u, v, w);
    }
    if (spfa(1)) cout << "yes" << endl; // exist
    else cout << "no" << endl; 
}