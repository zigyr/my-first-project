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
    int v, w, next;
    edge(){}
    edge(int _v, int _w, int _next){
        v = _v;
        w = _w;
        next = _next;
    }
} e[N << 1];

int head[N], inx;
void init(){
    memset(head, -1, sizeof head);
    inx = 0;
}

void insert(int u, int v, int w){
    e[inx] = edge(v, w, head[u]);
    head[u] = inx++;
}
void insert2(int u, int v, int w){
    insert(u, v, w);
    insert(v, u, w);
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
        // 灵活运用邻接表的链接效果
        for (int j = head[u]; ~j; j = e[j].next){
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
        insert2(u, v, w);
    }
    if (spfa(1)) cout << "yes" << endl; // exist
    else cout << "no" << endl; 
}