/*
4
1 3 2 4
-> 8
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn], a[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++){
        dp[i] = a[i];
        for (int j = 0; j < i; j++){
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}