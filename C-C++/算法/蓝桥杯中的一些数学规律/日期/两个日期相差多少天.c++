#include <iostream>
using namespace std;

int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year){
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int dayOfYear(int y, int m, int d){
    int sum = 0;
    for (int i = 1; i <= m; i++){
        sum += mday[i];
        if (i == 2 && isLeap(y)) sum++;
    }
    return sum + d;
}

int main (){
    int a = dayOfYear(2025, 1, 1);
    int b = dayOfYear(2025, 3, 1);
    cout << b - a << endl;
}