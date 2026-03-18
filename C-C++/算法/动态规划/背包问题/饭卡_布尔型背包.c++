/*
第一行输入正整数 n, 表示菜的数量
第二行输入 n 个正整数, 表示每种菜的价格, 不超过 50
第三行输入 m, 表示卡上的余额
(规则:
    购买一个商品之前, 卡上的余额大于或等于 5 元, 就一定可以购买成功,
    即使购买后卡上的余额为负;
    否则, 就无法购买, 即使金额足够    
)
输出卡上可能的最小余额

dp[j] 表示 是否存在花费为 j 的商品组合

5
7 12 15 2 8
25
-> -10

3
6 7 8
20
-> -1
*/
#include <iostream>
using namespace std;
#include <algorithm>

const int maxn = 1010;
int dp[maxn];
int a[maxn];

int main (){
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;

    sort(a, a + n);
    dp[0] = 1;
    int ma = 0;
    for (int i = 0; i < n; i++){
        for (int j = m - 5; j >= 0; j--){
            if (dp[j]){
                dp[j + a[i]] = 1;
                ma = max(ma, j + a[i]);
            }
        }
    }
    cout << m - ma << endl;
}