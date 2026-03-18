/*
现有 6种 娃娃, 第 i 种娃娃的萌值为 i
已知每种娃娃的数量mi, 蒜头君想知道能否把娃娃分成两组, 使得每组的娃娃的萌值之和相同
是, 输出" Can be divided"
否, 则输出" Can't be divided"

2 0 1 1 2 1
-> Can't be divided

2 2 2 2 2 2
-> Can be divided
*/
/*
二进制中, 
一个数的奇偶性由它的最低位决定
num & 1 = 1 -> 奇
num & 1 = 0 -> 偶
则 (num & 1) == (!(sum % 2))

另外, (num >>= 1) == (num /= 2)
*/
/*
dp[i] 表示:
    在 总萌值 不超过 j 的条件下,
    可达到的最大萌值

i 萌值 即 体积c, 价值w
a[i] 即 数量n
*/
#include <iostream>
using namespace std;

const int maxn = 1010;
int a[maxn];
int dp[maxn];

int main (){
    int sum = 0;
    for (int i = 0; i < 6; i++){
        cin >> a[i];
        sum += a[i] * i; 
    }

    if (sum & 1){
        cout << "Can't be divided" << endl;
        return 0;
    }
    sum >>= 1;

    for (int i = 0; i < 6; i++){
        int k;
        // 二进制枚举
        /*当 a[i] = 10 时：
            k = 1 2<11
            k = 2 4<11
            k = 4 8<11

            k = 8 16<11
            k = 10 - 8 + 1 = 3
        */
        for (k = 1; k * 2 < a[i] + 1; k <<= 1){
            for (int j = sum; j >= k * i; j--){
                dp[j] = max(dp[j], dp[j - k * i] + k * i);
            }
        }
        k = a[i] - k + 1;
        for (int j = sum; j >= k * i; j--){
            dp[j] = max(dp[j], dp[j - k * i] + k * i);
        }
    }

    if (sum == dp[sum]){
        cout << "Can be divided" << endl;
    } else{
        cout << "Can't be divided" << endl;
    }

}