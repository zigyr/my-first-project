/*
3 3
1 -2 3
-4 5 -6
7 -8 9
-> 9
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int prenum[maxn][maxn];
int ans = INT_MIN;
int a[maxn][maxn];

int main (){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        // 与 环形矩阵的最大子矩阵和 的类似
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
            for (int j = i + 1; j <= n; j++){
                int sum = 0;
                for (int k = 0; k < m; k++){
                    sum += prenum[j][k] - prenum[i - 1][k];
                    if (sum < 0) sum = 0;
                    ans = max(ans, sum);
                }
            }
        }
        cout << ans << endl;
    }
}