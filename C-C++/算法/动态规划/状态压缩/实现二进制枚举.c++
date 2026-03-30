/*
有n个互不相等的正整数
从中取不重复的正整数任意个
仅通过加法凑出整数x
求解方案个数
6 6 
1 2 3 4 5 6
-> 4
*/
#include <iostream>
using namespace std;


int main (){
    int n, x, ans = 0;
    cin >> n >> x;
    int a[20];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // n个正整数共可形成2**n个子序列
    for (int i = 0; i < (1 << n); i++){
        int num = 0;
        // 遍历这其中一个子序列的对应的一个长为n的二进制位上的值，作为是否累加的判断
        for (int j = 0; j < n; j++){
            if (i & (1 << j)){
                num += a[j];
            }
        }
        if (num == x){
            ans++;
        }
    }
    cout << ans << endl;
}