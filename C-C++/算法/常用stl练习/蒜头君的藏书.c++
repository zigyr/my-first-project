/*
4
English
Math
Chinese
Chinese
-> 3
-> Chinese 2
-> English 1
-> Math 1
*/
#include <iostream>
using namespace std;
#include <string>
#include <map>
map<string, int>m;
int main (){
    int n;
    cin >> n;
    string name;
    for (int i = 0; i < n; i++){
        cin >> name;
        m[name]++;
    }
    int cou = m.size();
    cout << cou << endl;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second <<endl;
    }
}