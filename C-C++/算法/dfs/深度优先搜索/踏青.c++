/*
入门
5 6
.#....
..#...
..#..#
...##.
.#....
-> 5
#号代表草地，连在一起的草地叫做草丛，统计草丛的个数
*/
#include <iostream>
using namespace std;
#include <string>

string maze[105];
int n, m;
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool in(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs (int x,int y){
    maze[x][y] = '.';
    for (int i = 0; i < 4; i++){
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx, ty) && maze[tx][ty] == '#')
            dfs(tx, ty);
    }
}
int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> maze[i];
    }

    int cou = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (maze[i][j] == '#'){
                cou++;
                dfs(i, j);
            }     
        }
    }

    cout << cou << endl;
}