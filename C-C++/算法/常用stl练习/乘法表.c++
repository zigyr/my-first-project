/*
通过制表符"\t"来修正对齐
*/
#include <iostream>
#include <vector>
using namespace std;

const int n = 9;


int main (){
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= i + 1; j++){
            cout << j << "*" << i + 1 << "=" << (i + 1) * j << "\t";
        }
        cout << endl;
    }
}