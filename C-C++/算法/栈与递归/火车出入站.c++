/*
很玄妙的一种思想
很玄妙的一种代码逻辑
米奇妙妙屋

火车出入站问题，也就是一个数组 1-n 依次进栈，判断其出栈的情况是否合法
输入： 第一行输入一个整数n，代表火车车厢个数，虽可能是乱序，但整体编号是从1到n
      第二行输入n个数字，代表待判断的出栈情况
输出：如果合法，legal；否则，illegal
7
1 3 2 7 6 5 4
-> legal
*/
#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int main (){
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    // 标志器
    bool flag = true;
    // 指向入栈前的对应火车
    int cur = 1;
    stack<int> s;
    for (int i = 0; i < n; i++){
        // 将vector中的, 也就是出栈后的数组a, 看作是一个栈
        // 其中初始状态的栈顶是a[0], 通过i对栈顶a[i]进行持续追踪
        
        // 这里是将为入栈的火车以此入栈
        // 直到当前入栈的火车编号与假设的栈顶元素相同
        while ((s.empty() || s.top() != a[i]) && cur <= n){
            s.push(cur++);
        }

        if (s.empty() || s.top() != a[i]){
            flag = false;
            break;
        } else
            s.pop();
    }

    if (flag)
        cout << "legal" << endl;
    else
        cout << "illegal" << endl;
}