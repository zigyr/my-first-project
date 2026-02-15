/*
从n个数中选k个数的和为sum
*/
#include <iostream>
using namespace std;
int n, k, sum, a[40], ans;
bool used[40];
void dfs(int s, int cnt){
    if(s == sum && cnt == k){
        ans++;
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
    // if( n == 1){
    //     return 1;
    // }
    // return f(n - 1) * n;
    return n == 1 ? 1 : f(n - 1) * n;
}
int main (){
    cin >> n >> k >> sum;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dfs(0, 0);
    
    cout << ans / f(k) << endl;
}