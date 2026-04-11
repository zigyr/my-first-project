#include <iostream>
using namespace std;

int n;
int a[100], edge[5];
bool vis[100];
bool flag;
int side;
int sum;

void dfs(int inx, int pos){
    if (flag)
        return;

    if (edge[inx] > side)
        return;

    if (inx == 4){
        flag = true;
        return;
    }

    if (edge[inx] == side)
        dfs(inx + 1, 0);
    else{
        for (int i = pos; i < n; i++){
            if (!vis[i]){
                vis[i] = true;
                edge[inx] += a[i];

                dfs(inx, pos + 1);

                vis[i] = false;
                edge[inx] -= a[i];

                if (flag)
                    return;
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

    if (sum % 4 != 0){
        cout << "No" << endl;
        return 0;
    } else{
        side = sum / 4;
        dfs(1, 0);
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}