/*
已知第一根柱子放了n片圆盘，从上到下以此编号为1-n
1号圆盘最小最轻，n号圆盘最大最重
移动第i号圆盘，需要i点体力
现在将第一根柱子上的圆盘全部移动到第二根柱子上，移动过程遵守汉诺塔游戏规则
问最小移动次数和最少消耗体力
*/
#include <iostream>
using namespace std;

long long cou[60],act[60];

int main (){
    int n;
    cin >> n;
    cou[1] = 1;
    act[1] = 1;
    //含有汉诺塔问题的递推思路
    //计算第i次的移动次数/消耗体力
    //其实就是在第i-1次的基础上以“汉诺塔问题的整体、分散原则”推出的
    //有点类似马尔科夫链
    /*
        个数：1   2   3   4   5  ...  n-1       n
        次数：1   3   7   15  31 ...  cou[n-1]  2*cou[n-1]+1
    */
    for (int i = 2; i <= n; i++){
        cou[i] = 2 * cou[i - 1] + 1;
        act[i] = 2 * act[i - 1] + i;
    }

    cout << "count: " << cou[n] << endl;
    cout << "action: " << act[n] << endl;
}