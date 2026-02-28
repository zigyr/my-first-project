/*
2025年12月25日之后40天是那一天
*/
#include <cstdio>

int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int year){
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}


int main (){
    int y = 2025, m = 12, d = 25;
    int n = 40;
    for (int i = 0; i < n; i++){
        d++;
        int days = mday[m];
        if (m == 2 && isLeap(y)) days++;
        if (d > days){
            d = 1;
            m++;
            if (m > 12){
                m = 1;
                y++;
            }
        }
    }
    printf("%d-%d-%d", y, m, d);
}