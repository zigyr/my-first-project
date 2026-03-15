/*
类 编辑距离
状态转移方程
    i == j:
        保持
    i != j:
        取dp[i-1][j]、dp[i][j-1]、dp[i-1][j-1]最优解
aa
ab
-> 1
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn];

int main (){
    string a, b;
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.size();
    for (int i = 1; i <= lena; i++) dp[i][0] = i;
    for (int i = 1; i <= lenb; i++) dp[0][i] = i;
    for (int i = 1; i <= lena; i++){
        for (int j = 1; j <= lenb; j++){
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    }
    cout << dp[lena][lenb] << endl;
}