// 输入一个数字
// 将这个数字与它反转过来的数字相加直至出现回文数
// 统计相加次数并记录每次的结果输出
#include <iostream>
using namespace std;

bool judge(int x){
    int num[100];
    int inx = 0;
    while (x){
        num[inx++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < inx; i++){
        if (num[i] != num[inx - 1 - i])
            return false;
    }
    return true;
}
int rev(int x){
    int res = 0;
    while (x){
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main (){
    int x;
    cin >> x;
    int cou = 0;
    int num[100];
    num[cou++] = x;
    while (!judge(x)){
        x += rev(x);
        num[cou++] = x;
    }
    cout << cou - 1 << endl;
    for (int i = 0; i < cou; i++){
        if (i > 0) cout << "--->";
        cout << num[i];
    }
}