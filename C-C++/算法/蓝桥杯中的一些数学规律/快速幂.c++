#include <iostream>
using namespace std;

typedef long long LL;

#define mod 1000

LL my_pow(LL a, LL b){
    LL res = 1;
    a = a % mod;

    /*
    2**13(1101):
              1    1    0    1    (0)
        a:  256   16    4  - 2 <-  2
      res: 8192   32    2  > 2  *--1
    */

    while(b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b = b >> 1;
    }

    return res;
}


int main (){
    LL a, b;
    cin >> a >> b;
    cout << my_pow(a, b);
}