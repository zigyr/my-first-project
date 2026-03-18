/*
一只容量为 V 的袋子
同时买 n 件物品, 已知每件物品的体积为 vi
问 挑选那些物品放入购物袋中, 可以使袋子剩余空间最小
输出 购物袋的最小剩余空间
3 10
6 
5 
4
-> 0
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn];

int main (){
    int N, V;
    cin >> N >> V;
    int c;
    for (int i = 0; i < N; i++){
        cin >> c;
        for (int j = V; j >= c; j--){
            dp[j] = max(dp[j], dp[j - c] + c);
        }
    }
    cout << V - dp[V] << endl;
}