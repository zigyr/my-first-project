/*
给定一个长度为 n 的序列 Ai
求L、R使(R-L+1)*min(AL,AL+1,...,AR)尽可能大
输出最大值
5
1 1 3 3 1
-> 6
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn];
int a[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        int current_min = a[i];
        dp[i] = a[i];

        for (int j = i - 1; j >= 0; j--){
            current_min = min(a[j], current_min);
            dp[i] = max(dp[i], current_min * (i - j + 1));
        }

        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}