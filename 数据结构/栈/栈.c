#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

// //static
// typedef struct{
//     ElemType data[MAXSIZE];
//     int top;
// }Stack;
// void initStack(Stack *s){
//     s->top=-1;
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

//isEmpty
int isEmpty(Stack *s){
    return s->top==-1;
}

//push
void push(Stack *s,ElemType e){
    if(s->top>=MAXSIZE){
        printf("full\n");
        return;
    }
    s->top++;
    s->data[s->top]=e;
}

//pop
void pop(Stack *s,ElemType *e){
    if(s->top==-1){
        printf("empty\n");
        return;
    }
    *e=s->data[s->top--];
}

//getTop
int getTop(Stack *s){
    return s->data[s->top];
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
    pop(s,&e);
    printf("%d\n",e);
    //getTop
    printf("%d\n",getTop(s));
    //isempty
    printf("%d\n",isEmpty(s));
}