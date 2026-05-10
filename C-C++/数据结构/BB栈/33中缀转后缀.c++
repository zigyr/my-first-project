#include <iostream>
using namespace std;

#include <map>
#include <stack>

/*
遍历中缀表达式
- 遇到数字，进入res字符串，并以#标识数字串的结束
- 遇到左括号，进栈
- 遇到右括号，将栈中的遇到的第一个左括号之前的运算符依次出栈并进入res字符串，然后将这个左括号出栈
- 遇到其他字符：
    if (栈空或这栈顶运算符为左括号) 入栈
    else if (该字符优先级高于栈顶运算符的优先级) 入栈
    else 依次出栈并存入res字符串中，直到该运算符的优先级高于栈顶运算符，然后将该运算符入栈

    即：
        - 遇到加号或减号，出栈运算符并放进res字符串，直到栈空或栈顶为左括号，然后将该加号或减号进栈
        - 遇到乘号或除号，出栈运算符并放进res字符串，
        直到栈空或栈顶为左括号、加号、减号，然后将该称号或除号进栈
*/

typedef char ElemType;

void in_symbol(map<char,int> &m){
    m.insert(make_pair('(', 0));

    m.insert(make_pair(')', 3));
    m.insert(make_pair('\0', 0));

    m.insert(make_pair('+', 1));
    m.insert(make_pair('-', 1));

    m.insert(make_pair('*', 2));
    m.insert(make_pair('/', 2));
    m.insert(make_pair('%', 2));

}
void out_symbol(map<char,int> &m){
    m.insert(make_pair('(', 4));
    
    m.insert(make_pair(')', 3));
    m.insert(make_pair('\0', 0));

    m.insert(make_pair('+', 1));
    m.insert(make_pair('-', 1));

    m.insert(make_pair('*', 2));
    m.insert(make_pair('/', 2));
    m.insert(make_pair('%', 2));
    
}

string eval(string expr){
    string res;
    stack<ElemType>s;
    s.push('\0');

    map<char,int> in_map; in_symbol(in_map);
    map<char,int> out_map; out_symbol(out_map);

    int index = 0;
    char tmp = expr[index++];

    while(tmp != '\0'){

        if(tmp >= '0' && tmp <= '9'){
            while (tmp >= '0' && tmp <= '9'){
                res += tmp;
                tmp = expr[index++];
            }
            res += '#';
        }

        // 遇到右括号，将栈中的遇到的第一个左括号之前的运算符依次出栈并进入res字符串，然后将这个左括号出栈
        else if (tmp == ')'){
            while(s.top() != '('){
                res += s.top();
                s.pop();
            }
            s.pop();
            tmp = expr[index++];
        }
        
        // 依次出栈并存入res字符串中，直到该运算符的优先级高于栈顶运算符，然后将该运算符入栈
        else {
            while( out_map.find(tmp)->second <= in_map.find(s.top())->second ){
                res += s.top();
                s.pop();
            }
            s.push(tmp);
            tmp = expr[index++];
        }
        
    }

    while(!s.empty()){
        res += s.top();
        s.pop();
    }

    return res;
}

int main (){
    string expr = "(56-20)/(4+2)";
    // 8/2+2-5*6 => 8#2#/2#+5#6#*-
    // (56-20)/(4+2) => 56#20#-4#2#+/
    cout<<eval(expr);
}