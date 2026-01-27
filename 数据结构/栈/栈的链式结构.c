#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//dynamic
typedef struct stack{
    ElemType data;
    struct stack *next;
}Stack;
Stack* initStack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->data=0;
    s->next=NULL;
    return s;
}

//isempty
int isempty(Stack *s){
    return s->next==NULL;
}

//push
void push(Stack *s,ElemType e){
    Stack *p=(Stack*)malloc(sizeof(Stack));
    p->data=e;
    p->next=s->next;
    s->next=p;
}

//pop
void pop(Stack *s,ElemType *e){
    if(s->next==NULL){
        printf("empty\n");
        return;
    }
    Stack *p=s->next;
    *e=p->data;
    s->next=p->next;
    free(p);
}

//getTop
int getTop(Stack *s){
    if(s->next==NULL){
        printf("empty");
        return 0;
    }
    return s->next->data;
}

int main (){
    //init-check
    Stack *s=initStack();
    //push pop isempty getTop-check
    push(s,40);
    push(s,30);
    push(s,20);
    push(s,10);
    while(!isempty(s)){
        printf("%d  ",getTop(s));
        int e;
        pop(s,&e);
        printf("%d\n",e);
    }
}