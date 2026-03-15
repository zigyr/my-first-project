/*
dp[i]:
    表示以第 i 个数为最后一个,
    能链接到的最大方案数
    (并非最优解, 需要ans遍历更新)
5
3 1 4 2 5
-> 2
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int a[maxn], dp[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
        for (int j = 1; j < i; j++){
            if (a[j] >= a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}