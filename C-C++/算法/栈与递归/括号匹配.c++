/*  
输入只有字符'('和')'组成的字符串
一个'('只能匹配唯一的')',第一个'('匹配最后一个')'
如果完全匹配，输出yes，
接下来若干行每行输出两个整数，
表示所有匹配的括号的位置；
如果不完全匹配，输出no。
*/
#include <iostream>
using namespace std;
#include <stack>
           
int main (){
    string s;
    cin >> s;

    int ans[1010] = {0};
    bool flag = true;
    stack<int> ss;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(')
            ss.push(i + 1);
        else{
            if (ss.empty()){
                flag = false;
                break;
            }

            ans[ss.top()] = i + 1;
            ss.pop();
        }
    }

    if (!ss.empty())
        flag = false;

    if (flag){
        cout << "yes" << endl;
        for (int i = 1; i <= s.size(); i++){
            if (ans[i])
                cout << i << " " << ans[i] << endl;
        }
    } else
        cout << "no" << endl;
}