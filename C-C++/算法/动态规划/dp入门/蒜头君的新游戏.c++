/*
击鼓传花, n 位同事(围成一圈), m 次传花
问有多少种情况, 使得从 同事A 开始传娃娃, 传了 m 次之后又回到 同事A 的手里
*/
#include <iostream>
using namespace std;

int dp[35][35];

int main (){
    int n, m;
    cin >> n >> m;
    // n 位同事
    // m 次传花
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (j == 1){
                dp[i][j] = dp[i - 1][n] + dp[i - 1][2];
            } else if (j == n){
                dp[i][j] = dp[i - 1][n - 1] + dp[i - 1][1];
            } else{
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }

        }
    }
    cout << dp[m][1] << endl;
}