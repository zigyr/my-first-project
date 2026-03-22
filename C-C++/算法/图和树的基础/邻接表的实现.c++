/*


10
1 2
2 4
3 4
5 6
7 9
10 1
8 9
9 5
3 7
3 8
-> 1 : 2 10 
-> 2 : 1 4
-> 3 : 4 7 8
-> 4 : 2 3
-> 5 : 6 9
-> 6 : 5
-> 7 : 9 3
-> 8 : 9 3
-> 9 : 7 8 5
-> 10 : 1
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> G[11];

int main (){
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= 10; i++){
        cout << i << " : ";
        // G[i].size() 返回的是 vector<int>::size_type 类型（无符号，本质是 unsigned long long）
        for (int j = 0; j < (int)G[i].size(); j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}