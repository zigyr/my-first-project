/*
3 12
1 3
2 2
2 3
2 4
3 1
3 6
1 5
1 2
1 6
3 2
3 7
1 1
-> 3 5 2 6 1
-> 2 3 4
-> 1 6 2 7
*/
#include <iostream>
#include <vector>
using namespace std;

int main (){
    int n, m;
    cin >> n >> m;
    vector<int> v[1000];
    int x, val;
    for (int i = 0; i < m; i++){
        cin >> x >> val;
        v[x].push_back(val);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < v[i].size(); j++){
            if(j > 0)cout << " ";
            cout << v[i][j];
        }
        cout << endl;
    }
}