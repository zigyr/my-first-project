#include <iostream>
using namespace std;
/*
s 是头节点
s->next 是栈顶
*/

typedef int ElemType;

struct Stack{
    ElemType data;
    Stack *next;
};
Stack* init(){
    Stack *s = new Stack;
    s->data = 0;
    s->next = nullptr;
    return s;
}

// DestroyStack
void DestroyStack(Stack *&s){
    Stack *pre = s;
    Stack *p = s -> next;
    while (p != nullptr){
        delete pre;
        pre = p;
        p = pre -> next;
    }
    delete pre;
}

//isEmpty
int isEmpty(Stack *s){
    return s->next == nullptr;
}

//push
void push(Stack *s, ElemType e){
    Stack *p = new Stack;
    p -> data = e;
    p -> next = s -> next;
    s -> next = p;
}

//pop
void pop(Stack *s, ElemType &e){
    if(s -> next == nullptr)
        return;
    Stack *p = s -> next;
    e = p-> data;
    s -> next = p -> next;
    delete p;
}

//getTop
int getTop(Stack *s){
    if(s -> next == nullptr)
        return 0;
    return s -> next -> data;
}


// P86
/*
判断输入的（只包含左括号、右括号）的表达式中括号是否匹配
*/
bool Match(string ss){
    Stack *s = init();

    for (int i = 0; i < ss.size(); i++){
        if (ss[i] == '(')
            push(s, '(');
        else{
            if (!getTop(s)){
                DestroyStack(s);
                return false;
            } 
            int e;
            pop(s, e);
        }
    }

    if (!isEmpty(s)){
        DestroyStack(s);
        return false;
    }
    DestroyStack(s);
    return true;
}

int main (){
    //init-check
    Stack *s = init();
    //push pop isEmpty getTop-check
    push(s, 40);
    push(s, 30);
    push(s, 20);
    push(s, 10);
    while (!isEmpty(s)){
        cout << getTop(s) << " ";
        int e;
        pop(s, e);
    }

    cout << endl;
    cout << endl;    

    string ss = "(()";
    cout << Match(ss) << endl;
}