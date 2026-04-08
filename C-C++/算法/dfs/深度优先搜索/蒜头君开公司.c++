/*
第一行输入一个整数 N , 代表有 N 个员工, 员工编号从1到N(1<=N<=10)
然后是一个 NxN 的二维矩阵task[N][N], 表示第i项工作由j号员工完成所需的时间
输出一个整数, 代表所需的最少时间之和
*/
#include <iostream>
using namespace std;

int n, ans = 0x3f3f3f3f;
int task[10][10];
int used[10];

// 在x层时, 还未进行选择时的耗时为t
void dfs(int x, int t){
    if (x == n){
        ans = min(t, ans);
        return;
    }

    for (int i = 0; i < n; i++){
        if (!used[i]){
            used[i] = true;
            dfs(x + 1, t + task[x][i]);
            used[i] = false;
        }
    }
}
int main (){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> task[i][j];
        }
    }
    dfs(0, 0);
    cout << ans << endl;
}