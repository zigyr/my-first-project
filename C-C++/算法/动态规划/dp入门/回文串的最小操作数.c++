/*
即, 将一个 普通字符串 变作 回文子串 的最小操作数
trit
-> 1
*/
/*
最大公共子序列的变种题
*/
#include <iostream>
using namespace std;
#include <algorithm>

const int maxn = 1010;
int dp[maxn][maxn];

int main (){
    string s1, s2;
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    int len = s1.size();
    for (int i = 1; i <= len; i++){
        for (int j = 1; j <= len; j++){
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << len - dp[len][len] << endl;
}