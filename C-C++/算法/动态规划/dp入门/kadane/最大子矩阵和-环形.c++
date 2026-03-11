/*
所谓环形矩阵,
即第一行与最后一行相连, 第一列与最后一列相连
最后一行的下一行为第一行
最后一列的下一列为第一列
3 3
1 -2 3
-4 5 -6
7 -8 9
20
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int a[maxn][maxn], prenum[maxn][maxn];
int ans = INT_MIN;

int main (){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            ans = max(ans, a[i][j]);
        }
    }
    if (ans <= 0){
        cout << ans << endl;
    } else{
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < m; j++){
                prenum[i][j] = prenum[i - 1][j] + a[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                for (int k = 0; k < m; k++){
                    int sum = 0;
                    for (int l = 0; l < m; l++){
                        int tmp;
                        if (i <= j){
                            tmp = prenum[j][(k + l) % m] - prenum[i - 1][(k + l) % m];
                        } else {
                            tmp = prenum[n][(k + l) % m] - (prenum[i - 1][(k + l) % m] - prenum[j][(k + l) % m]);
                        }
                        sum += tmp;
                        if (sum < 0) sum = 0;
                        ans = max(ans, sum);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}