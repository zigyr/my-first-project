/*
给定一个由数字组成的序列, 其中连续的一段子序列称为一个字段,
字段中的所有数之和称为字段和
而求一个序列中字段和最大的字段的字段和, 即最大字段和
6
-2 11 -4 13 -5 -2
20
*/
#include <iostream>
using namespace std;
#include <climits>

const int maxn = 1010;
int num[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num[i];
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++){
        ans = max(ans, num[i]);
    }
    if (ans <= 0){
        cout << ans << endl;
    } else{
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += num[i];
            if (sum < 0){
                sum = 0;
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}