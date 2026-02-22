/*
4
1 1 1 1
-> Yes
5
10 20 30 40 50
-> No
如果木棍能拼出正方形，输出"Yes"，否则输出"No"
*/
#include <iostream>
using namespace std;
int n, sum, s1;
bool ok, vis[20];
int le[4], a[20];

void dfs(int x, int j){
    if (x == 4){
        ok = true;
        return;
    }
    if (ok){
        return;
    }
    if (le[x] > s1){
        return;
    }
    if (le[x] == s1){
        dfs(x + 1, 1);
    } else{
        for (int f = j; f <= n; f++){
            if (!vis[f]){
                vis[f] = true;
                le[x] += a[f];

                dfs(x, f + 1);
                
                le[x] -= a[f];
                vis[f] = false;
            }
        }
    }
}
int main (){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    s1 = sum / 4;
    if (sum % 4 != 0){
        cout << "No" << endl;
        return 0;
    }
    dfs(1, 1);
    if (ok){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}