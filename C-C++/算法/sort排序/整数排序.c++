//将N个正整数按照除以3的余数从小到大排序，
//即将余0的数排在最前面，余2的数放在最后，
//如果余数相等，则按照正整数的值从小到大排序
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int a[maxn];

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, [](int a, int b){
        // if ((a % 3) != (b % 3)){
        //     return a % 3 < b % 3;
        // }
        // return a < b;
        if ((a % 3) == (b % 3))
            return a < b;
        return a % 3 < b % 3;
    });
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}