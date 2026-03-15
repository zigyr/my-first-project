/*
从(0,0,0)到(2,2,2)
2 2 2
1 2 3
4 5 6
7 8 9
1 2 3 
4 5 6
7 8 9
1 2 3
4 5 6
7 8 9
-> 23
*/
#include <iostream>
using namespace std;
const int N = 1e2 + 9;
const int inf = INT_MAX;

int f[N][N][N];

int main (){
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= y; j++){
            for (int k = 0; k <= z; k++){
                cin >> f[i][j][k];
            }
        }
    }
    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= y; j++){
            for (int k = 0; k <= z; k++){
                // 初始化 mi 无穷大
                int mi = inf;
                // 遍历左、下、后,
                // 得到最小的前驱消耗
                if (i){
                    mi = min(mi, f[i - 1][j][k]);
                }
                if (j){
                    mi = min(mi, f[i][j - 1][k]);
                }
                if (k){
                    mi = min(mi, f[i][j][k - 1]);
                }
                // 以“最小前驱消耗+当前点消耗”更新当前点的总消耗
                if (mi != inf){
                    f[i][j][k] += mi;
                }
            }
        }
    }
    cout << f[x][y][z] << endl;
}