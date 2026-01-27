#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

// //static
// typedef struct{
//     ElemType data[MAXSIZE];
//     int front,rear;
// }Queue;
// void initQueue(Queue* q){
//     q->front=0;
//     q->rear=0;
// }
//dynamic
typedef struct queue{
    ElemType *data;
    int front,rear;
}Queue;
Queue* initQueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    q->front=0;
    q->rear=0;
    return q;
}

//isempty
int isempty(Queue *q){
    return q->front==q->rear;
}

//push
int queueFull(Queue *q){
    if(q->front>0){
        int step=q->front;
        for(int i=q->front;i<=q->rear;i++){
            q->data[i-step]=q->data[i];
        }
        q->front=0;
        q->rear=q->rear-step;
        return 1;
    }else{
        printf("full\n");
        return 0;
    }
}
void push(Queue *q,ElemType e){
    if(q->rear>=MAXSIZE){
        if(!queueFull(q)){
            return;
        }
    }
    q->data[q->rear++]=e;
}

//pop
void pop(Queue *q,ElemType *e){
    if(q->front==q->rear){
        printf("empty\n");
        return;
    }
    *e=q->data[q->front++];
}

//getFront
int getFront(Queue *q){
    if(q->front==q->rear){
        printf("empty\n");
        return -1;
    }
    return q->data[q->front];
}

int main (){
    //init-check
    Queue *q=initQueue();
    //push
    push(q,10);
    push(q,20);
    push(q,30);
    push(q,40);
    //isempty getFront pop-check
    while(!isempty(q)){
        printf("the front of the queue is:%d\n",getFront(q));
        int e;
        pop(q,&e);
        printf("the front of the queue is:%d (by pop)\n",e);
    }
}