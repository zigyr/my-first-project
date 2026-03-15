/*
山谷子序列
    在一个序列中的子序列
    满足 先递减再递增 的趋势
6
4 3 5 2 3 1
-> 4
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[2][maxn], a[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        dp[0][i] = 1;
        for (int j = 0; j < i; j++){
            if (a[j] >= a[i]) dp[0][i] = max(dp[0][i], dp[0][j] + 1);
        }
    }
    for (int i = n - 1; i >= 0; i--){
        dp[1][i] = 1;
        for (int j = n - 1; j > i; j--){
            if (a[j] >= a[i]) dp[1][i] = max(dp[1][i], dp[1][j] + 1); 
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++){
        ans = max(ans, dp[0][i] + dp[1][i] - 1);
    }
    cout << ans << endl;
}