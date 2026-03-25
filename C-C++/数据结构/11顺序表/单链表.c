#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//dynatic
typedef struct node{
    ElemType data;
    struct node *next;
}Node;
Node* initList(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}

//insertHead
void insertHead(Node *L,ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    //注意不能是p->next=NULL;
    //因为这是头插法，p节点是要放前面的，让它下一个指向NULL，那还遍历啥
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
    return p;
}

//list
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
    p->next=q;
}

//deleteNode
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
    free(q);
}

//get_length
int get_length(Node *L){
    Node *p=L;
    int len=0;
    while(p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;
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

int main(){
    //init-check
    Node *list=initList();
    //headinsert-check
    insertHead(list,1);
    insertHead(list,2);
    insertHead(list,3);
    insertHead(list,4);
    //listNode-check
    listNode(list);
    //endinsert-check
    Node *tail=get_tail(list);
    tail=insertTail(tail,10);
    tail=insertTail(tail,11);
    tail=insertTail(tail,12);
    tail=insertTail(tail,13);
    listNode(list);
    //insertSuper-check
    insertSuper(list,11,100);
    listNode(list);
    //deleteNode-check
    deleteNode(list,6);
    listNode(list);
    //get_length-check
    printf("%d\n",get_length(list));
    //freeNode-check
    freeNode(list);
    printf("%d\n",get_length(list));
    return 1;
}