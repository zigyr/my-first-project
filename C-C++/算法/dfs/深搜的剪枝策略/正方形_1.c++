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

int n;
int a[100];
int sum;
int s;
bool flag;
bool vis[100];

void dfs(int inx, int ss){
    if (flag)
        return;

    if (ss > s)
        return;

    if (inx == 4){
        flag = true;
        return;
    }
    
    if (ss == s)
        dfs(inx + 1, 0);
    else{
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                vis[i] = true;
                dfs(inx, ss + a[i]);
                vis[i] = false;
            }
        }
    }
}

int main (){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 4){
        cout << "No" << endl;
        return 0;
    }else{
        s = sum / 4;
        dfs(1, 0);
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}