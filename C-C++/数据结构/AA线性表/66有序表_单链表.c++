#include <iostream>
using namespace std;

typedef int ElemType;

struct Node{
    ElemType data;
    Node *next;
};
Node* init(){
    Node *L = new Node;
    L -> data = 0;
    L -> next = nullptr;
    return L;
}

void ListInsert(Node *L, ElemType e){
    Node *pre = L;
    while (pre -> next != nullptr && pre -> next -> data < e)
        pre = pre -> next;

    Node *p = new Node;
    p -> data = e;
    p -> next = pre -> next;
    pre -> next = p;
}

void DispList(Node *L){
    Node *p = L -> next;
    while (p != nullptr){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

// 归并算法
// P67
void UnionList1(Node *LA, Node *LB, Node *&L){
    Node *pa = LA -> next;
    Node *pb = LB -> next;
    L = new Node;
    Node *r = L;

    while (pa != nullptr && pb != nullptr){
        if (pa -> data < pb -> data){
            Node *s = new Node;
            s -> data = pa -> data;
            r -> next = s;
            r = s;
            pa = pa -> next; 
        } else {
            Node *s = new Node;
            s -> data = pb -> data;
            r -> next = s;
            r = s;
            pb = pb -> next;
        }
    }

    while (pa != nullptr){
        Node *s = new Node;
        s -> data = pa -> data;
        r -> next = s;
        r = s;
        pa = pa -> next;
    }
    while (pb != nullptr){
        Node *s = new Node;
        s -> data = pb -> data;
        r -> next = s;
        r = s;
        pb = pb -> next;
    }

    r -> next = nullptr;
}

/* P68
3个带头节点的有序链表LA、LB、LC
假设每个单链表不存在数据值相同的节点, 但3个链表中可能存在数据值相同的节点
设计一个算法：使链表LA中仅留下3个表中均包含的数据元素的节点, 且没有数据值相同的节点, 并释放LA中的其他节点
*/
void Commnode(Node *&LA, Node *LB, Node *LC){
    Node *pa = LA -> next;
    Node *pb = LB -> next;
    Node *pc = LC -> next;
    LA -> next = nullptr;
    Node *r = LA;

    while (pa != nullptr){
        while (pb != nullptr && pa -> data > pb -> data)
            pb = pb -> next;
        while (pc != nullptr && pa -> data > pc -> data)
            pc = pc -> next;
        
        if (pb != nullptr && pc != nullptr && pa -> data == pb -> data && pa -> data == pc -> data){
            r -> next = pa;
            r = pa;
            pa = pa -> next;
        } else {
            Node *q = pa;
            pa = pa -> next;
            delete q;
        }
    }

    r -> next = nullptr;
}


/* P69
设置一个高效的算法删除值域重复的节点
*/
void dels(Node *L){
    Node *p = L -> next;
    while (p -> next != nullptr){
        if (p -> data == p -> next -> data){
            Node *q = p -> next;
            p -> next = q -> next;
            delete q;
        } else 
            p = p -> next;
        
    }
}


int main (){
    Node *L1 = init();
    Node *L2 = init();
    ListInsert(L1, 3);
    ListInsert(L1, 7);
    ListInsert(L1, 9);
    ListInsert(L1, 4);
    DispList(L1);
    ListInsert(L2, 2);
    ListInsert(L2, 7);
    ListInsert(L2, 5);
    ListInsert(L2, 4);
    DispList(L2);

    Node *L = init();
    UnionList1(L1, L2, L);
    DispList(L);
    
    dels(L);
    DispList(L);

    Commnode(L, L1, L2);
    DispList(L);

}