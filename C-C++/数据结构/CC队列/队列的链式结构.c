#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;


//dynamic
typedef struct queueNode{
    ElemType data;
    struct queueNode *next;
}QueueNode;
typedef struct{
    QueueNode *front;
    QueueNode *rear;
}Queue;
//始终维护这一个链式队列的头指针和尾指针
Queue* initQueue(){
    QueueNode *node=(QueueNode*)malloc(sizeof(QueueNode));
    node->data=0;
    node->next=NULL;

    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=node;
    q->rear=node;
    return q;
}

//入队
void equeue(Queue *q,ElemType e){
    QueueNode *node=(QueueNode*)malloc(sizeof(QueueNode));
    node->data=e;
    node->next=NULL;
    q->rear->next=node;//新增节点，建立链接
    q->rear=node;//移动q中的尾指针
}

//出队
void dequeue(Queue *q,ElemType *e){
    QueueNode *node=q->front->next;
    *e=node->data;
    q->front->next=node->next;
    if(q->rear==node){
        q->rear=q->front;
    }
    free(node);
}

//判断是否为空
int isEmpty(Queue *q){
    return q->front==q->rear;
}

//获取对头元素
ElemType getFront(Queue *q){
    if(isEmpty(q)){
        printf("empty\n");
        return 0;
    }
    return q->front->next->data;
}


int main (){
    Queue *q=initQueue();
    equeue(q,1);
    equeue(q,2);
    equeue(q,3);
    equeue(q,4);
    equeue(q,5);
    while(!isEmpty(q)){
        printf("%d ",getFront(q));
        ElemType e;
        dequeue(q,&e);
        printf("%d\n",e);
    }
}