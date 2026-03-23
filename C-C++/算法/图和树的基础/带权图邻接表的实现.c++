/*

10
1 2 3
2 4 4
3 4 2
5 6 1
7 9 0
10 1 -7
8 9 -4
9 5 10
3 7 11
3 8 20
-> (1, 2, 3)
-> (1, 10, -7)
-> (2, 1, 3)
-> (2, 4, 4)
-> (3, 4, 2)
-> (3, 7, 11)
-> (3, 8, 20)
-> (4, 2, 4)
-> (4, 3, 2)
-> (5, 6, 1)
-> (5, 9, 10)
-> (6, 5, 1)
-> (7, 9, 0)
-> (7, 3, 11)
-> (8, 9, -4)
-> (8, 3, 20)
-> (9, 7, 0)
-> (9, 8, -4)
-> (9, 5, 10)
-> (10, 1, -7)
*/
#include <iostream>
using namespace std;
#include <vector>


struct node{
    int v, w;
};

vector<node> G[11];

void insert1(int u, int v, int w){
    node tmp;
    tmp.v = v;
    tmp.w = w;
    G[u].push_back(tmp);
}

void insert2(int u, int v, int w){
    insert1(u, v, w);
    insert1(v, u, w);
}

void input(){
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        insert2(u, v, w);
    }
}

void output(){
    for (int i = 1; i <= 10; i++){
        for (int j = 0; j < G[i].size(); j++){
            cout << "(" << i << ", " << G[i][j].v << ", " << G[i][j].w << ")" << endl;
        }
    }
}

int main (){
    input();
    output();
}