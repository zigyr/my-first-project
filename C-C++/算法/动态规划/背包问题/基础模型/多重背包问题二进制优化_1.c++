/*
二进制拆分:
    按照二进制拆分规则对正整数 n 进行拆分, 
    得到的数组可通过 【选 / 不选】, 
    拼出从 0 ~ n 的任意整数
    比如：
    10 可以通过二进制拆分成 1, 2, 4, 3

5 10
2 1 2
3 5 3
2 5 1
3 4 2
4 3 8
-> 14
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn];
int w[maxn], c[maxn], n[maxn];
int nw[maxn], nc[maxn];

int main (){
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; i++){
        cin >> w[i] >> c[i] >> n[i];
    }

    // 二进制优化
    /* 
        二进制优化的思想是：
            总结一下, 就是将一个具有数量属性的物品拆分成多个没有数量属性的物品
            以此进行可以按照 01背包问题 的思路计算

            比如 对于一个物品1 (价值2, 体积1, 数量10)
            可以拆成
            物品a (价值2, 体积1) 1个
            物品b (价值4, 体积2) 2个
            物品c (价值8, 体积4) 4个
            物品d (价值6, 体积3) 3个
            后续物品以此类推, 利用游标 nn 去记录新的数组 nc、nw
    */
    int nn = 1;
    for (int i = 1; i <= N; i++){
        int k;
        // n[i] - (1 << k) + 1 > 0 即 (1 << k) - 1 < n[i] 
        // 利用等比数列求和
        // 则有 2^k - 1 = 1 + 2 + 4 + ………… + 2^(k-1)
        // 即存在 循环 与 代码 中的 k 的错位情况
        for (k = 1; n[i] - (1 << k) + 1 > 0; k++){
            nc[nn] = (1 << (k - 1)) * c[i];
            nw[nn] = (1 << (k - 1)) * w[i];
            nn++;
        }
        --k;
        nc[nn] = (n[i] - (1 << k) + 1) * c[i];
        nw[nn] = (n[i] - (1 << k) + 1) * w[i];
        nn++;
    }

    // 01背包求解
    for (int i = 1; i <= nn; i++){
        for (int j = V; j >= nc[i]; j--){
            dp[j] = max(dp[j], dp[j - nc[i]] + nw[i]);
        }
    }

    cout << dp[V] << endl;
}