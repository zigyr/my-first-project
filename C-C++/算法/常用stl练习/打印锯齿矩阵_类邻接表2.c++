/*
3 12
1 3
2 2
2 3
2 4
3 1
3 6
1 5
1 2
1 6
3 2
3 7
1 1
-> 1 6 2 5 3
-> 4 3 2
-> 7 2 6 1
*/
#include <iostream>
using namespace std;
#include <cstring>

const int N = 1e3 + 9;

struct edge{
    int v, next;
    edge(){}
    edge(int _v, int _next) : v(_v), next(_next) {}
} e[N << 1];

int head[N], inx;
void init(){
    memset(head, -1, sizeof(head));
    inx = 0;
}

void insert(int u, int v){
    e[inx] = edge(v, head[u]);
    head[u] = inx++;
}

int main (){
    init();
    int n, m;
    cin >> n >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        insert(u, v);
    }

    for (int i = 1; i <= n; i++){
        for (int j = head[i]; ~j; j = e[j].next){
            if (j != head[i]) cout << " ";
            cout << e[j].v;
        }
        cout << endl;
    }
}