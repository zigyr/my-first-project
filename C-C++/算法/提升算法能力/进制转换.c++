//输入两个数
//第一个即待转换数字
//第二个是几进制

#include <iostream>
using namespace std;

int main (){
    int x, r;
    cin >> x >> r;
    char res[100];
    int inx = 0;
    while (x){
        int tmp = x % r;
        if (tmp <= 9){
            res[inx++] = tmp + '0';
        } else{
            res[inx++] = tmp + 'A' - 10;
        }
        x /= r;
    }
    for (int i = inx - 1; i >= 0; i--){
        cout << res[i];
    }
    cout << endl;
}