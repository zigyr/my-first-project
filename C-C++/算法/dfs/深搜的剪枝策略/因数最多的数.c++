/*
3
10
100
1000
-> 6
-> 60
-> 840
输入一个数字 T，代表回合次数
接下来，输入输出 T 行 (1 <= T <= 100)
每行输入一个正整数 n (1 <= n <= 10**16)
每行输出一个正整数表示 含有最多因数个数的 数 (1 <= n)
*/
/*
x = p1**a1 * P2**a2 * p3**a3 * ... * pk**ak
那么当前 x 的因数个数 ans = (a1 + 1) * (a2 + 1) * (a3 + 1) * ... * (ak + 1) 
*/
/*
该算法的铁律：
1. 指数必须[非递增]
2**3 x 3**2 x 5**1 能搜
2**1 x 13**2 不能搜到
2. 质数必须从小到大连续使用
2**3 x 3**1 x 5**1 x 7**1 能搜
2**2 x 13**1 不能搜到
*/
/*
该算法大致思路：
会通过指数、因数的组合，
遍历到所有小于n的数字，
并从中找出目标
*/
#include <iostream>
using namespace std;

typedef long LL;
LL ans, mc, n;

const int prime[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

void dfs(int u, int m, LL x, LL cnt){
    if (cnt > mc){
        mc = cnt;
        ans = x;
    } else if (cnt == mc && x < ans){
        ans = x;
        // 如果 因数个数相同 , 选择 数小的
    }
    if (u == 15){
        return;
    }
    for (int i = 1; i <= m; i++){
        x = x * prime[u];
        if (x > n) break;
        dfs(u + 1, i, x, cnt * (i + 1));
    }
}

int main (){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        mc = 0;
        dfs(0, 60, 1, 1);
        cout << ans << endl;
    }
}