//输入一串数字
//计算每个数字的各个位数上的数字之和，谁小谁在前
//如果计算结果相同，则原数谁小谁在前
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

const int maxn = 1010;
int a[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    sort(a, a + n, [](int x, int y){
        int _x = x, _y = y;
        int x_tot = 0;
        int y_tot = 0;
        while (x){
            x_tot += (x % 10);
            x /= 10;
        }
        while (y){
            y_tot += (y % 10);
            y /= 10;
        }
        if (x_tot == y_tot)
            // 注意这里要用一对变量储存原值
            return _x < _y;
        return x_tot < y_tot;
    });

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}