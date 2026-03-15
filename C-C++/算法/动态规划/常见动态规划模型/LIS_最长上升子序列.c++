/*
最长上升子序列, 又称 LIS
在原序列中取任意多项, 不改变他们在原来数列中的次序,
得到的序列称为 原序列的子序列.
最大上升子序列, 就是给定序列中一个最长的、数值从高到低排列的子序列, 最长上升子序列不一定是唯一的
6
3 2 6 1 4 5
-> 3
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn], a[maxn], ans, n;

int LIS(){
    ans = INT_MIN;
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (a[j] < a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main (){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << LIS() << endl;
}