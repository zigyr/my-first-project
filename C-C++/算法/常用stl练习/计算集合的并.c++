/*
1 2
1
1 2
-> 1 2
*/
#include <iostream>
using namespace std;
#include <set>
#include <vector>

int main (){
    int n, m;
    cin >> n >> m;
    set<int>res;
    int tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        res.insert(tmp);
    }
    for (int i = 0; i < m; i++){
        cin >> tmp;
        res.insert(tmp);
    }
    for (set<int>::iterator it = res.begin(); it != res.end(); it++){
        cout << *it << " ";
    }
}