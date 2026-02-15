/*
3
100
1 2 
-1 2
1 2
-> 104
k1*x1**p1 + k2*x2**p2 + ··· + kn*xn**pn = 0
第一行n 代表一个n元的高次方程 (1<=n<=4)
第二行m 代表未知数大于等于1 小于等于m
接下来n行 每行输入两个数 分别表示ki、pi
输出可能的解的个数
*/
#include <iostream>
using namespace std;
int k[5], p[5];
int n, m, ans;
long poww(int x, int y){
    long ret = 1;
    for (int i = 0; i < y; i++){
        ret *= x;
    }
    return ret;
}
int res[5];
void dfs(int x, long s){
    if (x == n){
        if (s == 0){
            ans++;
            cout << "找到一组解" << endl;
            for (int i = 0; i < n; i++){
                cout << res[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= m; i++){
        res[x] = i;
        dfs(x + 1, s + k[x] * poww(i, p[x]));
    }
}
int main (){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> k[i] >> p[i];
    }
    dfs(0, 0);
    cout << ans << endl;
}