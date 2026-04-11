/*
给一个数n, 让找出一个只由0, 1组成的十进制数m
要求这个正整数m可以被n整除, 同时确保数字长度小于19, 多种可能, 任意一个即可
2
-> 10
*/
#include <iostream>
using namespace std;

int n;
bool flag;

void dfs(long m, int cnt){
    if (cnt >= 19 || flag) 
        return;

    if (m % n == 0){
        flag = true;
        cout << m << endl;
        return;
    }

    dfs(m * 10 + 0, cnt + 1);
    dfs(m * 10 + 1, cnt + 1);
} 
int main (){
    cin >> n;

    dfs(1, 0);    
}