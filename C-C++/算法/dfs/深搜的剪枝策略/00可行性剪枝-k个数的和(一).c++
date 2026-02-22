/*
30 8 200
-> 70
*/
#include <iostream>
using namespace std;
int n, k, sum, a[100], ans;

void dfs(int i, int c, int s){
    if (c > k || s > sum) return;
    if (i == n){
        if (c == k && s == sum) ans++;
        return;
    }
    dfs (i + 1, c, s);
    dfs (i + 1, c + 1, s + a[i]);
}
int main (){
    cin >> n >> k >> sum;
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
    }    
    dfs(0, 0, 0);
    cout << ans << endl;
}