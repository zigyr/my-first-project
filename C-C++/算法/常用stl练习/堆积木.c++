/*
巧妙
利用v[a].push_back(v[b][j])
将b数组中的元素追加到a中
并通过vector<int>().swap(v[b])对b进行清空
4 4
3 1
4 3
2 4
2 2
-> 
-> 2 4 3 1
-> 
->
*/
#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector<int> v[1000];
    int n, m;
    cin >> n >> m;
    // 初始原有数据, 这步也很重要
    for (int i = 1; i <= n; i++){
        v[i].push_back(i);
    }
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        if (a == b){
            continue;
        }
        for (int j = 0; j < v[b].size(); j++){
            v[a].push_back(v[b][j]);
        }
        // 清空b
        vector<int>().swap(v[b]);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < v[i].size(); j++){
            if (j > 0)cout<< " ";
            cout << v[i][j];
        }
        cout << endl;
    }
}