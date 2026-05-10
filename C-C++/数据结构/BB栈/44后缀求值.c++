#include <iostream> 
using namespace std;

#include <stack>

/*
遍历后缀表达式，
遇到数字进栈
遇到运算符，则出栈两个数字，并将运算结果进栈
    第一个出栈的在运算符右侧
    第二个出栈的在运算符左侧
直到遇到字符串结束标识符
*/
typedef int ElemType;

int eval(string expr){
    int index = 0;
    char tmp = expr[index++];

    stack<ElemType> s;
    
    while (tmp != '\0'){

        if (tmp >= '0' && tmp <= '9'){
            int d = 0;
            while (tmp >= '0' && tmp <= '9'){
                d = d * 10 + tmp - '0';
                tmp = expr[index++];
            }
            s.push(d);
        }

        else {
            int pos2 = s.top(); s.pop();
            int pos1 = s.top(); s.pop();

            if (tmp == '+')
                s.push(pos1 + pos2);

            else if (tmp == '-')
                s.push(pos1 - pos2);

            else if (tmp == '*')
                s.push(pos1 * pos2);

            else if (tmp == '/')
                s.push(pos1 / pos2);

            else if (tmp == '%')
                s.push(pos1 % pos2);
            
        }

        tmp = expr[index++];
    }
    
    return s.top();
}

int main (){
    string expr = "56#20#-4#2#+/";
    // 8#2#/2#+5#6#*- => -24
    // 56#20#-4#2#+/  => 6
    cout << eval(expr);    
}