#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

// //static
// struct Stack{
//     ElemType data[MAXSIZE];
//     int top;
// };
// void init(Stack *s){
//     s -> top = -1;
// }
//dynamic
struct Stack{
    ElemType *data;
    int top;
};
Stack* init(){
    Stack *s = new Stack;
    s -> data = new ElemType[MAXSIZE];
    s -> top = -1;
    return s;
}


// DestroyStack
void DestroyStack(Stack *s){
    delete s;
}


// isEmpty
int isEmpty(Stack *s){
    return s -> top == -1;
}

// push
void push(Stack *s, ElemType e){
    if (s->top == MAXSIZE - 1)
        return;
    s -> data[++s -> top] = e;
}

// pop
void pop(Stack *s, ElemType &e){
    if (s->top == -1)
        return;
    e = s -> data[s -> top--];
}

// getTop
int getTop(Stack *s){
    if (s -> top == -1)
        return -1;
    return s -> data[s -> top];
}


// P82
/*
利用栈判断一个字符串是不是对称串
*/
bool symmetry(string ss){
    Stack *s = init();
    for (int i = 0; i < ss.size(); i++)
        push(s, ss[i]);

    for (int i = 0; i < ss.size(); i++){
        int e;
        pop(s, e);
        if (e != ss[i]){
            DestroyStack(s);
            return false;
        }
    }

    DestroyStack(s);
    return true;
}


int main (){
    //init_static-check
    // Stack s;
    // init(&s);
    //init_dynamic-check
    Stack *s=init();
    //isempty
    printf("%d\n",isEmpty(s));
    //push
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    //pop
    int e;
    pop(s,e);
    printf("%d\n",e);
    //getTop
    printf("%d\n",getTop(s));
    //isempty
    printf("%d\n",isEmpty(s));

    cout << endl;

    string ss = "acbbca";
    cout << symmetry(ss) << endl;

    
}