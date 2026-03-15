/*
给定一个由数字组成的序列, 其中连续的一段子序列称为一个子段,
子段中的所有数之和称为子段和
而求一个序列中子段和最大的字段的子段和, 即最大子段和
6
-2 11 -4 13 -5 -2
20
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int a[maxn];
int ans = INT_MIN;

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    if (ans <= 0) cout << ans << endl;
    else {
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += a[i];
            if (sum < 0) sum = 0;
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}