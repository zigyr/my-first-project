/*
问题：
有42块巧克力和56块奶糖
要分成完全相同的若干份小礼包
巧克力和奶糖不能有剩余
请问最多能分成多少份

题眼：
最多、分完、无剩余、完全相同
*/
#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main (){
    int a = 42, b = 56;
    cout << gcd(42, 56);
}