#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 100
#include <cctype>
#include <stack>
//遍历后缀表达式，
//遇到数字进栈
//遇到运算符，则出栈两个数字，并将运算结果进栈
    //第一个出栈的在运算符右侧
    //第二个出栈的在运算符左侧
//知道遇到字符串结束标识符
typedef int ElemType;
// typedef struct{
//     ElemType *data;
//     int top;
// }Stack;
// Stack* initStack(){
//     Stack *s=(Stack*)malloc(sizeof(Stack));
//     s->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//     s->top=-1;
//     return s;
// }
// void push(Stack *s,ElemType e){
//     s->top++;
//     s->data[s->top]=e;
// }
// void pop(Stack *s,ElemType *e){
//     *e=s->data[s->top];
//     s->top--;
// }
int eval(stack<ElemType>&s,string expr){
    int pos1,pos2;
    int index=0;
    char tmp=expr[index++];
    while(tmp!='\0'){
        if(isdigit(tmp)){
            s.push(tmp-'0');
        }else{
            pos2=s.top();s.pop();
            pos1=s.top();s.pop();

            if(tmp=='+'){
                s.push(pos1+pos2);
            }else if(tmp=='-'){
                s.push(pos1-pos2);
            }else if(tmp=='*'){
                s.push(pos1*pos2);
            }else if(tmp=='/'){
                s.push(pos1/pos2);
            }else if(tmp=='%'){
                s.push(pos1%pos2);
            }

        }
        tmp=expr[index++];
    }
    return s.top();
}

int main (){
    stack<ElemType>s;
    string expr="82/2+56*-";
    cout<<eval(s,expr);    
}