/*
最长公共子序列: 给定两个序列 S1 和 S2, 求两者公共子序列 S3 的最大长度
状态转移:
    情况一：
        如果 s1 的第 i 项 等于 S2 的第 j 项,
        那么 S1[i] 与 S2[j] 作为公共子序列的结尾, 则 lcs[i][j] = lcs[i - 1][j - 1] + 1
    情况二：
        如果两者不相等,
        那么 S1[i] 与 S2[j] 不作为公共子序列的结尾, 则 lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1])
abcdefgh
acjlfabhh
-> 4
*/
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn];

int main (){
    string a, b;
    cin >> a >> b;

    // <cstring>
    memset(dp, 0, sizeof(dp));
    // 由于size的时间复杂度是O(n)
    // so 这里通过赋值减少size的时间消耗
    int lena = a.size();
    int lenb = b.size();

    for (int i = 1; i <= lena; i++){
        for (int j = 1; j <= lenb; j++){
            // 注意这里是a用i索引, b用j索引
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[lena][lenb] << endl;
}