#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//dynatic
struct Node{
    ElemType data;
    Node *next;
};
Node* initList(){
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=nullptr;
    return head;
}

//destoryList
void destoryList(Node *L){
    Node *p=L->next;
    Node *q;
    while(p!=nullptr){
        q=p->next;
        delete p;
        p=q;        
    }
    L->next=nullptr;
}

// listEmpty
bool listEmpty(Node *L){
    return L -> next == nullptr;
}

//listLength
int listLength(Node *L){
    Node *p=L;
    int len=0;
    while(p->next!=nullptr){
        p=p->next;
        len++;
    }
    return len;
}

//dispList
void dispList(Node *L){
    Node *p=L->next;
    while(p!=nullptr){
        printf("%d\n",p->data);
        p=p->next;
    }
}

// getElem
void getElem(Node *L, int pos, int &e){
    Node *p = L -> next;
    while(pos--){
        p = p -> next;
        if (p == nullptr){
            e = -1;
            return;
        }
    }
    e = p -> data;
}

// locateElem
int locateElem(Node *L, ElemType e){
    Node *p = L -> next;
    int cou = 1;
    while(p != nullptr){
        if (p -> data == e) break;
        cou++;
        p = p -> next;
    }
    if (p == nullptr) return 0;
    else return cou;
}

//listInsert
void listInsert(Node *L,int pos,ElemType e){
    Node *p=L;
    for(int i=0;i<pos-1;i++){
        p=p->next;
        if(p==nullptr){
            printf("incorrect:insert-position\n");
            return;
        }
    }
    Node *q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
}
//insertHead
void insertHead(Node *L,ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
}
//insertTail
Node* get_tail(Node *L){
    Node *p=L;
    while(p->next!=nullptr){
        p=p->next;
    }
    return p;
}
Node* insertTail(Node *tail,ElemType e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=nullptr;
    tail->next=p;
    return p;
}

//listDelete
void listDelete(Node *L,int pos){
    Node *p=L;
    for(int i=0;i<pos-1;i++){
        p=p->next;
        if(p==nullptr){
            printf("incorrect:delete-position\n");
            return;
        }
    }
    Node *q=p->next;
    p->next=q->next;
    delete q;
}


int main(){
    //init-check
    Node *list=initList();
    //headinsert-check
    insertHead(list,1);
    insertHead(list,2);
    insertHead(list,3);
    insertHead(list,4);
    
    int e;
    getElem(list, 10, e);
    printf("%d\n", e);

    int inx = locateElem(list, 5);
    printf("%d\n", inx);
}