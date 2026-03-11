/*
编辑距离：
    对于标准字符串 S, 对字符串 T 的单个字符进行 替换、删除、插入 等操作后, 能换成字符串 S 的操作数
    即 编辑距离
而本题正是求解最小编辑距离 
（编辑距离越小, 代表两个字符串的相似度越大）
abcd
acef
-> 3
*/
/*
dp[i][j]：
    表示把 T的前j个字符 变成 S的前i个字符

状态转移方程(四种情况)：
    S 的第 i 个字符, 与 T 的第 j 个字符
    对应：
        dp[i][j] = dp[i - 1][j - 1]
    不对应：
        替换:
            dp[i - 1][j - 1] + 1
            (把 T 的第 j 个字符"T[j-1]", 转换成 S 的第 i 个字符"S[i-1]")
        删除:
            dp[i][j - 1] + 1
            (删除 T 的第 j 个字符"T[j-1]")
        插入：
            dp[i - 1][j] + 1
            (在 T 的末尾插入 S 的第 i 个字符"S[i-1]")
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn];

int main (){
    string a, b;
    cin >> a >> b;
    int lena = a.size();
    int lenb = b.size();
    for (int i = 1; i <= lena; i++){
        dp[i][0] = i;
    }
    for (int i = 1; i <= lenb; i++){
        dp[0][i] = i;
    }
    for (int i = 1; i <= lena; i++){
        for (int j = 1; j <= lenb; j++){
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            } else{
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    cout << dp[lena][lenb] << endl;
}