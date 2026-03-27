/*
能不重复的遍历图中的所有边(欧拉图)
if(起点==终点)欧拉回路
else(起点!=终点)欧拉路径
*/
/*
欧拉回路：每个节点的入度等于出度
欧拉路径：恰有一个节点(起点)的：出度 = 入度 + 1
         恰有一个节点(终点)的：入度 = 出度 + 1
*/
/*
4 4
2 1
3 2
1 3
2 4
-> It has an euler path!
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
// degree 用来记录每个节点的入度与出度的差值
int degree[maxn];

int euler(){
    int first = 0, last = 0;
    for (int i = 1; i <= n; i++){
        if (degree[i] < -1 || degree[i] > 1){
            cout << "It doesn't have an euler path!" << endl;
            return -1;
        } else if (degree[i] == -1){
            if (first != 0){
                cout << "It doesn't have an euler path!" << endl;
                return 0;
            } else{
                first = i;
            }
        } else if (degree[i] == 1){
            if (last != 0){
                cout << "It doesn't have an euler path!" << endl;
                return 0;
            } else {
                last = i;
            }
        }
    }
    if (first == 0 && last == 0){
        cout << "It has an euler circuit!" << endl;
        return 1;
    } else if (first != 0 && last != 0){
        cout << "It has an euler path!" << endl;
        return first;
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
        degree[u]--;
        degree[v]++;
    }
    euler();
}