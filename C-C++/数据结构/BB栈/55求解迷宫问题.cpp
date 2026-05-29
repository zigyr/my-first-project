#include <iostream>
using namespace std;
#include <stack>

int n, m;
string maze[105];
bool vis[105][105];

bool in(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

struct Node{
    int x, y, dir;
};
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


bool dfs_stack(int x, int y){
    stack<Node>st;
    
    st.push({x, y, 0});
    vis[x][y] = true;

    while(!st.empty()){
        Node &cur = st.top();

        // 是否到达终点
        if (maze[cur.x][cur.y] == 'T')
            return true;

        // 判断是否越界
        if (cur.dir == 4){
            // 回溯
            if (maze[cur.x][cur.y] != 'S')
                maze[cur.x][cur.y] = '.';
            
            vis[cur.x][cur.y] = false;
            st.pop();
            continue;
        }

        int tx = cur.x + dirs[cur.dir][0];
        int ty = cur.y + dirs[cur.dir][1];

        cur.dir++;

        if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] != '*'){

            vis[tx][ty] = true;

            if (maze[tx][ty] != 'T')
                maze[tx][ty] = 'm';

            st.push({tx, ty, 0});

        }
    }
    return false;
}


int main (){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> maze[i];
    }

    int sx, sy;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (maze[i][j] == 'S')
                sx = i, sy = j;
        }
    }

    if (dfs_stack(sx, sy)){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << maze[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "Not Path!" << endl;
    }
}