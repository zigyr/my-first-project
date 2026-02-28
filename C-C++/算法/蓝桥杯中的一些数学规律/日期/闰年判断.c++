#include <iostream>
using namespace std;

bool isLeap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main (){
    cout << isLeap(2024) << endl;
}