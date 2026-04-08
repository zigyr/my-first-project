#include <iostream>
using namespace std;

typedef int ElemType;

//dynamic
struct Node{
    ElemType data;
    struct Node *next,*prev;
};
Node* init(){
    Node *head = new Node;
    head -> data = 0;
    head -> next = nullptr;
    head -> prev = nullptr;
    return head;
}

// HeadInsert
void HeadInsert(Node *L, ElemType e){
    Node *p = new Node;
    p -> data = e;
    p -> next = L -> next;
    p -> prev = L;
    if(L -> next != nullptr)
        L -> next -> prev = p;
    L -> next = p;
}

// TailInsert
Node* get_tail(Node *L){
    Node *p = L;
    while (p->next != nullptr){
        p = p -> next;
    }
    return p;
}
Node* TailInsert(Node *tail, ElemType e){
    Node *p = new Node;
    p -> data = e;
    p -> next = nullptr;
    tail -> next = p;
    p -> prev = tail;
    return p;
}

//listNode
void listNode(Node *L){
    Node *p = L -> next;
    while(p != nullptr){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

//ListInsert
void ListInsert(Node *L, int pos, ElemType e){
    Node *p = L;
    for(int i = 0; i < pos-1; i++){
        p = p -> next;
        if (p == nullptr){
            cout << "incorrect:insert-position" << endl;
            return;
        }
    }
    Node *q = new Node;
    q -> data = e;
    q -> next = p -> next;
    q -> prev = p;
    if (p -> next != nullptr)
        p -> next -> prev = q;
    p -> next = q;
}

//ListDelete
void ListDelete(Node *L, int pos){
    Node *p = L;
    for(int i = 0; i < pos-1; i++){
        p = p -> next;
        if (p == nullptr){
            cout << "incorrect:ListDelete-position" << endl;
            return;
        }
    }
    Node *q = p -> next;
    p -> next = q -> next;
    q -> next -> prev = p;
    delete q;
}

//DestoryList
void DestoryList(Node *L){
    Node *p = L -> next;
    Node *q;
    while (p != nullptr){
        q = p -> next;
        delete p;
        p = q;
    }
    L -> next = nullptr;
}

//getLength
int getLength(Node *L){
    Node *p = L -> next;
    int len = 0;
    while(p != nullptr){
        p = p -> next;
        len++;
    }
    return len;
}

/* P57
 设计一个算法
 将所有元素逆置
 即第一个元素变成最后一个元素、第二个元素变成倒数第二个元素
*/
void reverse_1(Node *L){
    Node *p = L -> next;
    L -> next = nullptr;
    while (p != nullptr){
        Node *q = p -> next;
        p -> next = L -> next;
        p -> prev = L;
        if (L -> next != nullptr){
            L -> next -> prev = p;
        }
        L -> next = p;
        p = q;
    }
}
// void reverse_2(Node *L){
//     Node *first = L;
//     Node *second = L -> next;
//     Node *third = nullptr;
//     while (second != nullptr){
//         third = second -> next;
//         second -> next = first;

//         first = second;
//         second = third;
//     }
//     Node *q = init();
//     q -> next = first;
//     q -> prev = nullptr;
// }


/* P58
 设计一个算法
 使链表L按照元素的data域递增排序
*/
void sort(Node *&L){
    Node *p = L -> next -> next;
    L -> next -> next = nullptr;
    while (p != nullptr){
        Node *q = p -> next;
        Node *pre = L;
        while (pre -> next != nullptr && pre -> next -> data < p -> data)
            pre = pre -> next;
        p -> next = pre -> next;
        p -> prev = pre;
        if (pre -> next != nullptr)
            pre -> next -> prev = p;
        pre -> next = p;
        p = q;
    }
}


int main (){
    Node *l = init();
    Node *tail = get_tail(l);
    tail = TailInsert(tail, 1);
    tail = TailInsert(tail, 2);
    tail = TailInsert(tail, 3);
    tail = TailInsert(tail, 4);
    tail = TailInsert(tail, 5);
    listNode(l);
    reverse_1(l);
    listNode(l);
    sort(l);
    listNode(l);
}