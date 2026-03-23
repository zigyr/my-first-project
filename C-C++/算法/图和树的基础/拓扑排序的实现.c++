/*
4 3
1 2
3 2
2 4
-> 1
-> 3
-> 2
-> 4
*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1001;

struct edge{
    int v, next;
    int len;
} e[N << 1];

int head[N], len;
void init(){
    memset(head, -1, sizeof(head));
    len = 0;
}

void insert(int u, int v){
    e[len].v = v;
    e[len].next = head[u];
    head[u] = len++;
}

int n, m;
int indegree[N];

void topo(){
    queue<int>q;
    for (int i = 1; i <= n; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << endl;
        for (int i = head[u]; ~i; i = e[i].next){
            int v = e[i].v;
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }
}

int main (){
    init();
    memset(indegree, 0, sizeof(indegree));
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        insert(u, v);
        indegree[v]++;
    }
    topo();
}