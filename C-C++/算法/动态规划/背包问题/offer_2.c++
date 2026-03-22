/*
n表示拥有美元数, m表示待选择的大学
每个学校都有不同的申请费用a万美元,
并且估计能得到这个学校offer的可能性为b
请计算, 至少收到一份offer的最大概率
*/
/*
dp[j] 表示
    花费j元时, 没拿到任何一份offer的概率

10 3
4 0.1
4 0.2
5 0.3
-> 44.0%
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>

const int maxn = 1010;
double dp[maxn];

int main (){
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i <= maxn; i++){
        dp[i] = 1.0;
    }
    
    while(m--){
        int x; double y;
        std::cin >> x >> y;
        for(int j = n; j >= x; j--){
            dp[j] = std::min(dp[j], dp[j - x] * (1 - y));
        }
    }
    printf("%.1lf%%\n", (1 - dp[n]) * 100);
}