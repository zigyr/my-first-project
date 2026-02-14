/*
输入：
* 2 6 * * * * * *
* * * 5 * 2 * * 4
* * * 1 * * * * 7
* 3 * * 2 * 1 8 *
* * * 3 * 9 * * *
* 5 4 * 1 * * 7 *
5 * * * * 1 * * *
6 * * 9 * 7 * * *
* * * * * * 7 5 *
输出：
1 2 6 7 3 4 5 9 8
3 7 8 5 9 2 6 1 4
4 9 5 1 6 8 2 3 7
7 3 9 4 2 5 1 8 6
8 6 1 3 7 9 4 2 5
2 5 4 8 1 6 3 7 9
5 4 7 2 8 1 9 6 3
6 1 3 9 5 7 8 4 2
9 8 2 6 4 3 7 5 1
*/
#include <cstdio>
char maze[15][15];
bool vx[15][15], vy[15][15], vv[15][15];
bool f;
void dfs(int x, int y){
    // printf("%d %d\n", x, y);
    if (f){
        return;
    }
    if (x == 9){
        f = true;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (j > 0){
                    printf(" ");
                }
                printf("%c", maze[i][j]);
            }
            printf("\n");
        }
        return;
    }
    if (y == 9){
        dfs(x + 1, 0);
        return;
    }
    // 注意maze判断的位置
    // 不能放在最前面
    if (maze[x][y] != '*'){
        dfs(x, y + 1);
        return;
    }
    for (int i = 1; i <= 9; i++){
        if (!vx[x][i] && !vy[y][i] && !vv[x / 3 * 3 + y / 3][i]){
            // printf("%d %d\n", x, y);
            maze[x][y] = i + '0';
            vx[x][i] = true;
            vy[y][i] = true;
            vv[x / 3 * 3 + y / 3][i] = true;
            dfs(x, y + 1);
            maze[x][y] = '*';
            vx[x][i] = false;
            vy[y][i] = false;
            vv[x / 3 * 3 + y / 3][i] = false;
        }
    }
}
int main (){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            scanf(" %c", &maze[i][j]);
        }
    }
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (maze[i][j] != '*'){
                vx[i][maze[i][j] - '0'] = true;
                vy[j][maze[i][j] - '0'] = true;
                vv[i / 3 * 3 + j / 3][maze[i][j] - '0'] = true;
            }
        }
    }
    dfs(0, 0);
}