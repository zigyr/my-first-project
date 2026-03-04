/*
4
   3
  1 2
 6 2 3
3 5 4 1
-> 15
*/
#include <iostream>
#include <climits>
using namespace std;
const int N = 1e3 + 9;
int f[N][N];
int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> f[i][j];
        }
    }
    // 双层 for循环计 算最后一层每一个的值
    // 方便后续比较
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i; j++){
            // 这里的 max 直接选择能量值更大的那一条
            f[i][j] += max(f[i - 1][j], f[i - 1][j - 1]);
            // 每一个点, 都只由它上方两个点的[最优解]推出
            // 每一层, 都是[最优解]构成的
            // 所以, 下一层也必然是[最优解]
            // 所以, 不会出现 局部最优解的情况
        }
    }
    int ma = INT_MIN;
    for (int i = 1; i <= n; i++){
        ma = max(ma, f[n][i]);
    }
    cout << ma << endl;
}
//    1          1
//   1 2        2 3
//100 1 1    102 4 4