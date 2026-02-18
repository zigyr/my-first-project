/*
从n个数中选k个数的和为sum
测试一:（秒出）
    5 3 9
    1 2 3 4 5
    -> 2
测试二:（几乎不行）
    30 8 200
    -> 70
*/
#include <iostream>
using namespace std;
int n, k, sum, a[40], ans;
bool used[40];
void dfs(int s, int cnt){
    if (cnt == k){
        if (s == sum){
            ans++;
        }
    }
    for(int i = 0; i < n; i++){
        if(!used[i]){
            used[i] = true;
            dfs(s + a[i], cnt + 1);
            used[i] = false;
        }
    }
}
int f(int n){
    return n == 1 ? 1 : f(n - 1) * n;
}
int main (){
    cin >> n >> k >> sum;
    for(int i = 0; i < n; i++){
        // cin >> a[i];
        a[i] = i + 1;
    }
    dfs(0, 0);
    cout << ans / f(k)  << endl;
}