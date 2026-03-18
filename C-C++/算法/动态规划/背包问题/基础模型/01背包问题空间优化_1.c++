/*
dp[j]:
    表示容量为 j 时的最优解
    
5 10
2 1 
3 5
2 5 
3 4
4 3
-> 9
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn];
int w[maxn], c[maxn];

int main (){
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; i++){
        cin >> w[i] >> c[i];
    }
    for (int i = 1; i <= N; i++){
        for (int j = V; j >= c[i]; j--){
            dp[j] = max(dp[j - c[i]] + w[i], dp[j]);
        }
    }
    cout << dp[V] << endl;
}