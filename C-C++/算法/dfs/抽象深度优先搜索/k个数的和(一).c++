/*
从n个数中选k个数的和为sum
测试一:（秒出）
    5 3 9
    1 2 3 4 5
    -> 2
测试二:（等了一会）
    30 8 200
    -> 70
*/
#include <iostream>
using namespace std;
int a[40];
int n, k, sum, ans;
void dfs(int i, int cnt, int s){
    if(i == n){
        if(cnt == k && s == sum){
            ans++;
        }
        return;
    }
    //不能写成
    //dfs(i++, cnt, s);
    dfs(i + 1, cnt, s);//不选
    dfs(i + 1, cnt + 1, s+a[i]);//选
}
int main (){
    cin >> n >> k >>sum;
    for (int i = 0; i < n; i++){
        // cin >> a[i];
        a[i] = i + 1;
    }
    dfs(0, 0, 0);
    cout << ans <<endl;
}