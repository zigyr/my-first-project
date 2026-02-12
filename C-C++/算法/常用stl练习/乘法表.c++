/*
通过制表符"\t"来修正对齐
*/
#include <iostream>
#include <vector>
using namespace std;
const int n = 9;


int main (){
    vector< vector<int> > v;
    for (int i = 0; i < n; i++){
        v.push_back(vector<int>());
    }
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j <= i; j++){
            v[i].push_back((i + 1) * (j + 1));
        }
    }
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j <= i; j++){
            cout << j + 1 << "*" << i + 1 << "=" << v[i][j] << "\t";
        }
        cout << endl;
    }
    // for (int i = 0; i < n; i++){
    //     for (int j = 1; j <= i + 1; j++){
    //         cout << j << "*" << i + 1 << "=" << (i + 1) * j << "\t";
    //     }
    //     cout << endl;
    // }
}