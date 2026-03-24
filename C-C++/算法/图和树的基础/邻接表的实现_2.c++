/*
链式前向星
用途：竞赛最常用，速度快、省空间
本质：用数组模拟链表的邻接表
10
1 2
2 4
3 4
5 6
7 9
10 1
8 9
9 5
3 7
3 8
-> (1): 10, 2;
-> (2): 4, 1;
-> (3): 8, 7, 4;
-> (4): 3, 2;
-> (5): 9, 6;
-> (6): 5;
-> (7): 3, 9;
-> (8): 3, 9;
-> (9): 5, 8, 7;
-> (10): 1;
*/
#include <iostream>
using namespace std;
#include <cstring>

const int N = 1e3 + 9;

struct edge{
    int v, next;
    edge(){}
    edge(int _v, int  _next){
        v = _v;
     next =  _next;
    }
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
void insert2(int u, int v){
    insert(u, v);
    insert(v, u);
}

int main (){
    init();
    int m;
    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        insert2(u, v);
    }
    for (int i = 1; i <= 10; i++){
        cout << "(" << i << "): ";
        for (int j = head[i]; ~j; j = e[j].next){   
            if (j != head[i]) cout << ", ";
            cout << e[j].v;
        }
        cout << ";" << endl;
    }
}