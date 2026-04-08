/*
输入一个数字，代表操作次数
每次操作分为
    打开页面 VISIT 网址
    回退     BACK
    前进     FORWARD
如果每次操作成功，输出此次操作之后的网址，否则输出“Ignore”
*/
#include <iostream>
#include <stack>
using namespace std;

int main (){
    int n;
    cin >> n;

    /*
        s1{A -> B[为back做准备] -> A[当前浏览页面]} --》s2{D -> E[为forward做准备]}
    */
    stack<string> s1, s2;

    while (n--){
        string op, addr;

        cin >> op;

        if (op[0] == 'V'){
            cin >> addr;
            s1.push(addr);
            /*
                如果访问了新的页面
                那么将无法forward, so栈s2将被清空
            */
            while (!s2.empty())
                s2.pop();
        } else if (op[0] == 'B'){
            if (s1.size() <= 1){
                cout << "Ignore" << endl;
                continue;
            }
            s2.push(s1.top());
            s1.pop();
        } else{
            if (s2.empty()){
                cout << "Ignore" << endl;
                continue;
            }
            s1.push(s2.top());
            s2.pop();
        }

        cout << s1.top() << endl;
    }
}