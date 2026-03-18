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
int nw[maxn], nc[maxn];

int main (){
    int N, V;
    cin >> N >> V;
    
    int w, c, n;
    for (int i = 0; i < N; i++){
        cin >> w >> c >> n;
        int k;
        for (k = 1; k * 2 < n + 1; k <<= 1){
            for (int j = V; j >= k * c; j--){
                dp[j] = max(dp[j], dp[j - c * k] + w * k);
            }
        }
        k = n - k + 1;
        for (int j = V; j >= k * c; j--){
            dp[j] = max(dp[j], dp[j - c * k] + w * k);
        }
    }

    cout << dp[V] << endl;
}