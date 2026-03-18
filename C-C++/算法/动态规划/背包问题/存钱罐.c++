/*
第一行输入两个整数 e、f, 表示存钱罐的初始重量和现在重量
第二行输入一个整数 n, 表示有 n 中硬币
接下来 n 行, 每行有两个整数 p、w, 表示硬币的面额和重量

如果这些钱可以凑出存钱罐的重量, 那么输出存钱罐中最少有多少钱
否则, 输出"impossible"

dp[i] 表示在 i 重量下的, 最少金钱

1 6
2
10 3
20 4
-> impossible
*/
#include <iostream>
using namespace std;
#include <cstring>

const int maxn = 1010;
int dp[maxn];
const int inf = 0x3f3f3f3f;

int main (){
    memset(dp, inf, sizeof(dp));
    int e, f;
    cin >> e >> f;
    int V = f - e;
    int n;
    cin >> n;
    int p, w;
    for (int i = 1; i <= n; i++){
        cin >> p >> w;
        for (int j = w; j <= V; j++){
            dp[j] = min(dp[j], dp[j - w] + p);
        }
    }
    if (dp[V] == inf){
        cout << "impossible" << endl;
    } else{
        cout << dp[V] << endl;
    }
}