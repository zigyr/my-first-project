/*
假如有n个连续的弹簧板，每个站一个单位距离
第i个弹簧板可选择把小球向前弹a[i]或b[i]个距离
现在小球掉到1号弹簧板上，请计算至少/最少弹起多少次，才会弹出弹簧板（1号弹簧板也算一次）
*/
#include <iostream>
using namespace std;
#include <algorithm>

/*
#include <cstdio>
#include <algorithm>
int a[200],b[200];
int ans[200];
bool vis[200];
int n;
// 递归+记忆化搜索(Memorization)
// 
int f(int x){
    if(x>=n){
        return 0;
    }
    if(vis[x]){
        return ans[x];
    }
    vis[x]=true;
    return ans[x]=std::min(f(x+a[x]),f(x+b[x]))+1;
}

*/

int n;
int a[1010], b[1010];
bool vis[1010];
int ans[1010];

/*f(x) 表示 起始位置如果是 x 的话, 需要弹跳的最小次数*/
int f(int x){
    if (x > n)
        return 0;

    if (vis[x])
        return ans[x];

    return ans[x] = min(f(x + a[x]), f(x + b[x])) + 1;
}

int main (){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }    
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    cout << f(0) << endl;
}