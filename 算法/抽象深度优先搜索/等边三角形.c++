/*
输入：第一行输入一个整数n(3<=n<=10), 表示木棍数量, 接下来输入n根木棍的长度
输出：如果能拼出等边三角形，输出“yes”；否则，输出“no”
*/
#include <iostream>
using namespace std;
int n, a[15], sum;
bool f, vis[15];
void dfs(int cnt, int s){
    if(f) return;
    if(cnt == 3) {
        f = true;
        return;
    }
    if(s == sum/3) return dfs(cnt + 1, 0);
    for( int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(cnt, s + a[i]);
            vis[i] = false;
        }
    }
}
int main (){
    cin >> n;
    for( int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    dfs(0, 0);
    if( sum % 3 == 0){
        if(f) cout << "yes" << endl;
        else  cout << "no" <<endl;
    } else {
        cout << "no" <<endl;
    }
}