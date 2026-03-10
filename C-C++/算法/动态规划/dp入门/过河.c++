/*
夜晚, n 个小朋友过桥, 每次只能过两个, 所花费时间由速度最慢的小朋友决定
同时只有一个手电筒, 每次过桥后, 需要有同学把手电筒带回来
第 i 号小朋友的过桥时间为 a[i]
问所有小朋友过桥的总时间最短是多少

*/
#include <iostream>
using namespace std;
#include <algorithm>

const int maxn = 1010;

int a[maxn], dp[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    // 这里的dp[i]表示总共i个小朋友过河的最优解
    // 当只有一个小朋友时, 最优解就是跑的最快的一个小朋友产生的
    // 当只有两个小朋友时, 最优解就是跑到最快的两个小朋友产生的
    dp[1] = a[1];
    dp[2] = a[2];
    for (int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 1] + a[1] + a[i], dp[i - 2] + a[1] + 2 * a[2] + a[i]);
    }
    cout << dp[n] << endl;
}