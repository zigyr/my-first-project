/*
问题：
有N个物品，
每袋装K个，
问最少要多少袋
题眼：
每袋装几个、装不完也要用一盒、至少多少盒
*/
/*
在不影响整除结果的前提下，
强行把余数部分顶上去
*/
#include <iostream>
using namespace std;

int main (){
    int n, k;
    cin >> n >> k;
    cout << (n + k - 1) / k;
}