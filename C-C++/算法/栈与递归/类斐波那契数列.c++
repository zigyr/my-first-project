/*
fn表示新数列的第n项
f1=f2=1, fn=a*fn-1 + b*fn-2(n>2)
输入4个整数，n、a、b、p
输出fn对p取模的值
*/
#include <iostream>
using namespace std;

int f(int n, int a, int b, int p){
    if (n == 1 || n == 2)
        return 1;
    
    return (a * f(n - 1, a, b, p) + b * f(n - 2, a, b, p)) % p;
}

int main (){
    int n, a, b, p;
    cin >> n >> a >> b >> p;
    cout << f(n, a, b, p) << endl;
}