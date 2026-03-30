/*
酒有两斗
逢店加一倍, 遇花喝一斗
路上共遇店5次，遇花10次
已知最后一次遇到的是花，正好把酒喝完
计算花和店的遇到次序，问有多少种不同的可能
*/
/*
`i & (1 << j)`
判断二进制i从右数第j+1的位置是否为1
*/
#include <iostream>
using namespace std;

int main (){
    int ans = 0;
    for (int i = 0; i < (1 << 14); i++){
        int tot_1 = 0;
        int tot_0 = 0;
        int num = 2;
        for (int j = 0; j < 14; j++){
            if (i & (1 << j)){
                tot_1++;
                num = num * 2;
            } else {
                tot_0++;
                num = num - 1;
            }
        }
        if (tot_1 == 5 && tot_0 == 9 && num == 1){
            ans++;
        }
    }
    cout << ans << endl;
}