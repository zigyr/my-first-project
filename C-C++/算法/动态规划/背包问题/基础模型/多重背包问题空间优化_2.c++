/*
dp[j]:
    表示容量为 j 时的最优解

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
int w, c, n;

int main (){
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; i++){
        cin >> w >> c >> n;
        for (int j = V; j >= 0; j--){
            for (int k = 0; k <= n; k++){
                if (j >= c * k){
                    dp[j] = max(dp[j], dp[j - c * k] + w * k);
                }      
            }
        }
    }
    cout << dp[V] << endl;
}