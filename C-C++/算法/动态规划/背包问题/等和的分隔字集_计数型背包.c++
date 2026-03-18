/*
将一个 1 到 N 的连续整数组成的集合划分成两个子集和,
且保证每个集合的数字和是相等的
问划分方案有多少种

第一行输入一个整数, 表示 N 的值

输出划分的方案数, 当没办法划分时, 输出0

dp[j] 表示 前 j 个序列的方案数

7
-> 4
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn];

int main (){
    int N;
    cin >> N;
    int sum = N * (N + 1) / 2;
    if (sum & 1){
        cout << 0 << endl;
        return 0;
    }
    sum >>= 1;
    dp[0] = 1;
    for (int i = 1; i <= N; i++){
        for (int j = sum; j >= i; j--){
            dp[j] += dp[j - i];
        }
    }
    cout << dp[sum] / 2 << endl;
}