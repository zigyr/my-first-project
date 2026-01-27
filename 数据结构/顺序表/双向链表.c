#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//dynamic
typedef struct node{
    ElemType data;
    struct node *next,*prev;
}Node;
Node* initList(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    head->prev=NULL;
    return head;
}

//insertHead
void insertHead(Node *L,ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    p->prev=L;
    if(L->next!=NULL){
        L->next->prev=p;
    }
    L->next=p;
}

//insertTail
Node* get_tail(Node *L){
    Node *p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}
Node* insertTail(Node *tail,ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    tail->next=p;
    p->prev=tail;
    return p;
}

//listNode
void listNode(Node *L){
    Node *p=L->next;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

//insertSuper
void insertSuper(Node *L,int pos,ElemType e){
    Node *p=L;
    for(int i=0;i<pos-1;i++){
        p=p->next;
        if(p==NULL){
            printf("incorrect:insert-position\n");
            return;
        }
    }
    Node *q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    q->prev=p;
    p->next=q;
    p->next->prev=q;
}

//delete
void deleteNode(Node *L,int pos){
    Node *p=L;
    for(int i=0;i<pos-1;i++){
        p=p->next;
        if(p==NULL){
            printf("incorrect:delete-position\n");
            return;
        }
    }
    Node *q=p->next;
    p->next=q->next;
    q->next->prev=p;
    free(q);
}

//freeNode
void freeNode(Node *L){
    Node *p=L->next;
    Node *q;
    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}

//get_length
int get_length(Node *L){
    Node *p=L->next;
    int len=0;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

int main (){
    //init-check
    Node *list=initList();
    //insertHead-check
    insertHead(list,4);
    insertHead(list,3);
    insertHead(list,2);
    insertHead(list,1);
    //listNode-check
    listNode(list);
    //insertTail-check
    Node *tail=get_tail(list);
    tail=insertTail(tail,8);
    tail=insertTail(tail,9);
    tail=insertTail(tail,10);
    tail=insertTail(tail,11);
    listNode(list);
    //insertSuper-check
    insertSuper(list,6,100);
    listNode(list);
    //deleteNode-check
    deleteNode(list,6);
    listNode(list);
    //freeNode-check
    //get_length-check
    freeNode(list);
    printf("%d\n",get_length(list));
}