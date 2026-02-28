/*
已知2024年3月1日是星期五
求2024年5月1日是星期几
*/
#include <iostream>
using namespace std;

int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string week[7] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

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
    int day1 = dayOfYear(2025, 3, 1);
    int day2 = dayOfYear(2025, 5, 5);
    int diff = day2 - day1;
    int old_week = 5;
    int new_week = (old_week + diff) % 7;
    cout << week[new_week] << endl;
}