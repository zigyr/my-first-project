#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

// //static
// struct Stack{
//     ElemType data[MAXSIZE];
//     int top;
// };
// void initStack(Stack *s){
//     s -> top = -1;
// }
//dynamic
typedef struct stack{
    ElemType *data;
    int top;
}Stack;
Stack* initStack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top=-1;
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
    if(s->top == MAXSIZE - 1)
        return;
    s -> top++;
    s -> data[s -> top] = e;
}

// pop
void pop(Stack *s, ElemType &e){
    if(s->top==-1)
        return;
    e = s -> data[s -> top--];
}
void pop(Stack *s, ElemType *e){
    *e = s -> data[s -> top--];
}

// getTop
int getTop(Stack *s){
    return s -> data[s -> top];
}

int main (){
    //init_static-check
    // Stack s;
    // initStack(&s);
    //init_dynamic-check
    Stack *s=initStack();
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
}