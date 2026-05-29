#include <iostream>
using namespace std;

typedef int ElemType;


struct QueueNode{
    ElemType data;
    struct QueueNode *next;
};
struct Queue{
    QueueNode *front;
    QueueNode *rear;
};
//始终维护这一个链式队列的头指针和尾指针
Queue* init(){
    Queue *q = new Queue;
    q -> front = nullptr;
    q -> rear = nullptr;
    return q;
}

// DestroyQueue
void DestroyQueue(Queue *q){
    QueueNode *pre = q -> front;
    if (pre != nullptr){
        QueueNode *p = pre -> next;
        while (p != nullptr){
            delete pre;
            pre = p;
            p = p -> next;
        }
        delete pre;
    }
    delete q;
}

//enQueue
void enQueue(Queue *q,ElemType e){
    QueueNode *node = new QueueNode;
    node -> data = e;
    node -> next = NULL;
    if (q -> rear == nullptr)    //若链栈为空, 则新节点既是首节点又是尾节点
        q -> front = q -> rear = node;
    else {
        q -> rear -> next = node;//新增节点，建立链接
        q -> rear = node;        //移动q中的尾指针
    }
}

//判断是否为空
bool isEmpty(Queue *q){
    return q -> rear == nullptr;
}

//deQueue
bool deQueue(Queue *q, ElemType &e){
    if (isEmpty(q))
        return false;
    
    if (q -> front == q -> rear)
        q -> front = q -> rear = nullptr;
    else
        q -> front = q -> front -> next;

    QueueNode *node = q -> front;
    e = node -> data;

    delete node;
    return true;
}

//获取对头元素
ElemType getFront(Queue *q){
    if(isEmpty(q)){
        cout << "empty" << endl;
        return 0;
    }
    return q -> front -> next -> data;
}


int main (){
    Queue *q=init();
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    while(!isEmpty(q)){
        printf("%d ",getFront(q));
        ElemType e;
        deQueue(q, e);
        printf("%d\n",e);
    }
}