/*
问题：
小明每4天去一次操场，小红每6天去一次
今天他们一起去了操场
问至少再过多少天，他们又会同一天去操场

题眼：
至少、同一天、再次相遇
*/
#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main (){
    int a = 4, b = 6;
    int lcm = a * b / gcd(a, b);
    cout << lcm << endl;
}