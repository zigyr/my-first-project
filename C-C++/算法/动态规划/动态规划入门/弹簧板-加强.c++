/*
第一行输入一个整数 n
第二行输入 n 个数字, 表示每个弹簧可以将小球向前弹几次

现在希望计算小球从任意一个弹簧板落下, 最多被弹起几次, 才会弹出弹簧板
*/
#include <iostream>
using namespace std;

const int maxn = 10010;
int a[maxn], dp[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    // 注意这里是倒着推的
    for (int i = n; i >= 0; i--){
        /*
        dp[i]
            表示第 i 个弹簧
            弹几次可以弹出去
        */
        dp[i] = dp[i + a[i]] + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}