/*
3 2
1 3 2
1 2
-> 2
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn];
int a[maxn];
int b[maxn];

int main (){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    int maxx;
    for (int i = 1; i <= n; i++){
        maxx = 0;
        for (int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j];
            if (a[i - 1] > b[j - 1]) maxx = max(maxx, dp[i - 1][j]);
            else if (a[i - 1] == b[j - 1]) dp[i][j] = maxx + 1;
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= m; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}