/*
n表示拥有美元数, m表示待选择的大学
每个学校都有不同的申请费用a万美元,
并且估计能得到这个学校offer的可能性为b
请计算, 至少收到一份offer的最大概率
*/
/*
dp[j] 表示
    花费j元时, 至少拿到一份offer的概率

10 3
4 0.1
4 0.2
5 0.3
-> 44.0%
*/
/*
P(A) = f[j - x]
P(B) = y
P(A交B) = y * f[j - x]
P(A并B) = P(A) + P(B) - P(A交B)
        = f[j - x] + y - y * f[j - x]
        = f[j - x] + y * (1 - f[j - x])
        = 1 - (1 - f[j - x]) + y * (1 - f[j - x])
        = 1 - (1 - f[j - x]) * (1 - y)
*/ 
#include <iostream>
#include <algorithm>
#include <stdio.h>

const int maxn = 1010;
double dp[maxn];

int main (){
    int n, m;
    std::cin >> n >> m;

    while(m--){
        int x; double y;
        std::cin >> x >> y;
        for(int j = n; j >= x; j--){
            dp[j] = std::max(dp[j], 1 - (1 - dp[j - x]) * (1 - y));
        }
    }
    printf("%.1lf%%\n", dp[n] * 100);
}