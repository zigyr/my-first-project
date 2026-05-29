#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

//static
typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}Queue;
void init(Queue* q){
    q -> front = 0;
    q -> rear = 0;
}
// //dynamic
// typedef struct queue{
//     ElemType *data;
//     int front,rear;
// }Queue;
// Queue* init(){
//     Queue *q=(Queue*)malloc(sizeof(Queue));
//     q->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//     q->front=0;
//     q->rear=0;
//     return q;
// }

// Destroy
void DestroyQueue(Queue *q){
    delete q;
}

// QuesuEmpty
int QuesuEmpty(Queue *q){
    return q -> front == q -> rear;
}

// enQusue
bool queueFull(Queue *q){
    if (q -> front > 0){
        int step = q -> front;
        for(int i = q -> front; i <= q -> rear; i++){
            q -> data[i - step] = q -> data[i];
        }
        q -> front = 0;
        q -> rear = q -> rear - step;
        return true;
    } else{
        printf("full\n");
        return false;
    }
}
void enQusue(Queue *q, ElemType e){
    if (q -> rear >= MAXSIZE){
        if(!queueFull(q)){
            return;
        }
    }
    q -> data[q -> rear++] = e;
}

// deQueue
void deQueue(Queue *q,ElemType &e){
    if(q -> front == q -> rear){
        printf("empty\n");
        return;
    }
    e = q -> data[q -> front++];
}

//getFront
int getFront(Queue *q){
    if(q -> front == q -> rear){
        printf("empty\n");
        return -1;
    }
    return q -> data[q -> front];
}

int main (){
    // //init-check
    // Queue *q=init();
    // //enQusue
    // enQusue(q,10);
    // enQusue(q,20);
    // enQusue(q,30);
    // enQusue(q,40);
    // //QuesuEmpty getFront deQueue-check
    // while(!QuesuEmpty(q)){
    //     printf("the front of the queue is:%d\n",getFront(q));
    //     int e;
    //     deQueue(q,e);
    //     printf("the front of the queue is:%d (by deQueue)\n",e);
    // }
    Queue q;
    init(&q);
    // Queue *q;
    // init(q);
}