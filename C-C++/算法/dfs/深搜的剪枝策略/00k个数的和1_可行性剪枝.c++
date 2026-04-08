/*
题目：组合求和计数
    给定三个整数：
    n：数字范围是 1 ~ n 的连续整数
    k：需要选出 k 个不同的数字
    sum：选出的 k 个数字之和必须等于 sum
    求：满足条件的组合一共有多少种？

30 8 200
-> 70
*/
#include <iostream>
using namespace std;

int n, k, sum;
int a[100], ans;

void dfs(int i, int c, int s){
    if (c > k || s > sum)
        return;
    
    if (i == n){
        if (c == k && s == sum)
            ans++;
        return;
    }

    // 选
    dfs(i + 1, c + 1, s + a[i]);
    // 不选
    dfs(i + 1, c, s);
}

int main (){
    cin >> n >> k >> sum;
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
    }

    dfs(0, 0, 0);
    cout << ans << endl;
}