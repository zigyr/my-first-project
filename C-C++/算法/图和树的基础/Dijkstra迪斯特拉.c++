/*
1-- 5 --2
|       |
----    5
  2|    |
   -----3
3 3
1 2 5
2 3 5
3 1 2
-> 2
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1001;
const int inf = 0x3f3f3f3f;

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

bool vis[N];
int dis[N];
void dijkstra(int u){
    memset(vis, false, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    dis[u] = 0;
    for (int i = 0; i < n; i++){
        int mind = inf, minj = -1;
        for (int j = 1; j <= n; j++){
            if (!vis[j] && dis[j] < mind){
                mind = dis[j];
                minj = j;
            }
        }
        if (minj == -1) return;
        vis[minj] = true;
        for (int j = head[minj]; ~j; j = e[j].next){
            int v = e[j].v;
            int w = e[j].w;
            if (!vis[v] && dis[v] > dis[minj] + w){
                dis[v] = dis[minj] + w;
            }
        }
    }
}


int main (){
    init();
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        insert2(u, v, w);
    }
    dijkstra(1);
    cout << dis[n] << endl;
}