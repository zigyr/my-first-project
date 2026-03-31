#include <iostream>
using namespace std;

typedef int ElemType;

// dynatic
struct Node{
    ElemType data;
    Node *next;
};
Node* init(){
    Node *head = new Node;
    head->data = 0;
    head->next = nullptr;
    return head;
}

// DestroyList
void DestroyList(Node *L){
    Node *p = L->next;
    Node *q;
    while(p != nullptr){
        q = p->next;
        delete p;
        p = q;        
    }
    L->next = nullptr;
}

// ListEmpty
bool ListEmpty(Node *L){
    return L -> next == nullptr;
}

// ListLength
int ListLength(Node *L){
    Node *p = L;
    int len = 0;
    while(p->next != nullptr){
        p = p -> next;
        len++;
    }
    return len;
}

// DispList
void DispList(Node *L){
    Node *p = L->next;
    while(p != nullptr){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

// GetElem
void GetElem(Node *L, int pos, int &e){
    Node *p = L;
    while(pos--){
        p = p -> next;
        if (p == nullptr){
            e = -1;
            return;
        }
    }
    e = p -> data;
}

// LocateElem
int LocateElem(Node *L, ElemType e){
    Node *p = L;
    int inx = 0;
    while(true){
        inx++;
        p = p -> next;
        if (p -> data == e) break;
        if (p == nullptr) return -1;
    }
    return inx;
}

// ListInsert
void ListInsert(Node *L, int pos, ElemType e){
    Node *p = L;
    // 找到待插入位置的前置节点
    for (int i = 0; i < pos - 1; i++){
        p = p -> next;
        if (p == nullptr){
            cout << "[ListInsert]:position_error" << endl;
            return;
        }
    }
    Node *q = new Node;
    q -> data = e;
    q -> next = p -> next;
    p -> next = q;
}
// HeadInsert
void HeadInsert(Node *L, ElemType e){
    Node *p = new Node;
    p -> data = e;
    p -> next = L->next;
    L -> next = p;
}
// TailInsert
Node* getTail(Node *L){
    Node *p = L;
    while(p -> next != nullptr){
        p = p -> next;
    }
    return p;
}
Node* TailInsert(Node *tail, ElemType e){
    Node *p = new Node;
    p -> data = e;
    p -> next = nullptr;
    tail -> next = p;
    return p;
}

// ListDelete
void ListDelete(Node *L, int pos){
    Node *p = L;
    // 找到待删除位置的前置节点
    for (int i = 0; i < pos - 1; i++){
        p = p -> next;
        if (p == nullptr){
            cout << "[ListDelete]:position_error" << endl;;
            return;
        }
    }
    Node *q = p -> next;
    p -> next = q -> next;
    delete q;
}

/*
将带有头节点的L=(a1, b1, a2, b2, a3, b3, ......, an, bn)
拆分成两个带有头节点的L1、L2
L1=(a1, a2, a3, ......, an) 尾插
L2=(bn, ......, b3, b2, b1) 头插
要求L1使用L的头节点
*/
// P51-split
void split(Node *L, Node *&L1, Node *&L2){
    Node *p = L -> next, *r1, *s;
    L1 = L;
    r1 = L1;

    L2 = new Node; 
    L2 -> next = nullptr;

    while(p != nullptr){
        // L1 尾插
        r1 -> next = p;
        r1 = p;
        p = p -> next;

        // L2 头插
        s = p;
        // 由于s=p导致后续s->next=L2->next的操作已经间接的影响到了p与p->next
        p = p -> next;
        // 所以必须放在之前
        s -> next = L2 -> next;
        L2 -> next = s;
        
    }
    r1 -> next = nullptr;
}


/*
设计一个算法
删除一个单链表L中元素值最大的节点(假设这样的节点唯一)
*/
// P52-delmaxnode
void delmaxnode(Node *L){
    Node *p = L -> next, *pre = L;
    Node *max = p, *maxpre = pre;

    while(p != nullptr){
        if (p -> data > max -> data){
            max = p;
            maxpre = pre;
        }
        p = p -> next;
        pre = pre -> next;
    }

    maxpre -> next = max -> next;
    delete max;
}


/*
设计一个算法
实现所有数据节点按data域递增排序
*/
// P53-sort
void sort(Node *L){
    // p 从第二个数据节点开始，保留了以L为头节点的链条
    Node *p = L -> next -> next;
    // L 作为未来返回的有序链条，作为结果的容器进行断开操作
    // 不过幸好有p保留了火种
    L -> next -> next = nullptr;
    while(p != nullptr){
        Node *q = p -> next;
        Node *pre = L;
        // 每次利用while循环通过p去遍历原有链条的数据节点
        // 同时每次都用pre去遍历结果链条, 去找到当前p节点的可以插入的位置
        // 如此保证了L的有序性
        while(pre -> next != nullptr && pre -> next -> data < p -> data)
            pre = pre -> next;
        p -> next = pre -> next;
        pre -> next = p;
        p = q;
    }
}


int main(){
    //init-check
    Node *list=init();
    //headinsert-check
    HeadInsert(list,1);
    HeadInsert(list,2);
    HeadInsert(list,3);
    HeadInsert(list,4);
    DispList(list);

    int e;
    GetElem(list, 1, e);
    cout << e << endl;

    int inx = LocateElem(list, 4);
    cout << inx << endl;


    // split
    Node *L = init();
    Node *tail = getTail(L);
    tail = TailInsert(tail, 0);
    tail = TailInsert(tail, 1);
    tail = TailInsert(tail, 2);
    tail = TailInsert(tail, 3);
    tail = TailInsert(tail, 4);
    tail = TailInsert(tail, 5);
    tail = TailInsert(tail, 6);
    tail = TailInsert(tail, 7);
    tail = TailInsert(tail, 8);
    tail = TailInsert(tail, 9);
    tail = TailInsert(tail, 10);
    tail = TailInsert(tail, 11);
    DispList(L);
    Node *L1 = nullptr, *L2 = nullptr;
    split(L, L1, L2);
    DispList(L1);
    DispList(L2);



    delmaxnode(list);
    DispList(list);



    sort(list);
    DispList(list);
}