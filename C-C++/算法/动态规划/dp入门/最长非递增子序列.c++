/*
5
3 1 4 2 5
-> 2
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int a[maxn], dp[maxn];
int ans = INT_MIN;

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (a[j] >= a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}