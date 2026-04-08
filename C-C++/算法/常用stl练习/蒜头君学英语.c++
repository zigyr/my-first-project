/*
5
0 we
0 are
1 family
0 Family
1 Family
-> No
-> Yes
0表示会 1表示测试
对于每次测试, 如果会, Yes
否则, No
*/
#include <iostream>
using namespace std;
#include <set>
set<string> s;
int main (){
    int n;
    cin >> n;
    int op;
    string ss;
    for (int i = 0; i < n; i++){
        cin >> op >> ss;
        // 转小写
        for (int j = 0; j < ss.size(); j++){
            if (ss[j] >= 'A' && ss[j] <= 'Z'){
                ss[j] = ss[j] - 'A' + 'a';
            }
        }
        if (op == 0){
            s.insert(ss);
        } else {
            if (s.count(ss)){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}