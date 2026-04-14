/* 以递增方式排列的线性表 */
#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef int ElemType;


struct SqList{
    ElemType *data;
    int length;
};
SqList* init(){
    SqList *L = new SqList;
    L -> data = new ElemType[MAXSIZE];
    L -> length = 0;
    return L;
}

int ListLength(SqList *L){
    return L -> length;
}

void ListInsert(SqList *L, ElemType e){
    int i = 0;
    while (i < L -> length && L -> data[i] < e)
        i++;
    
    for (int j = ListLength(L); j > i; j--)
        L -> data[j] = L -> data[j - 1];
    
    L -> data[i] = e;
    L -> length++;
}

// 归并算法
// P66
void UnionList(SqList *LA, SqList *LB, SqList *&LC){
    LC = init();
    int i = 0, j = 0, k = 0;

    while (i < LA -> length && j < LB -> length){
        if (LA -> data[i] < LB -> data[j]){
            LC -> data[k] = LA -> data[i];
            i++;
            k++;
        } else {
            LC -> data[k] = LB -> data[j];
            j++;
            k++;
        }
    }

    // LA 尚未遍历完, 将其余元素插入到LC中
    while (i < LA -> length){
        LC -> data[k] = LA -> data[i];
        i++;
        k++;
    }
    // LB 尚未遍历完, 将其余元素插入到LC中
    while (j < LB -> length){
        LC -> data[k] = LB -> data[j];
        j++;
        k++;
    }

    LC -> length = k;
}

void DispList(SqList *L){
    for (int i = 0; i < ListLength(L); i++)
        cout << L -> data[i] << " ";
    cout << endl;
}

/* P69
寻找两个等长的升序序列的中位数,
即两个升序序列合并后的中位数
默认中间位置, 不论奇偶(s->data[s->length/2])
*/
ElemType M_Search(SqList *A, SqList *B){
    int i = 0, j = 0, k = 0;
    while (i < A -> length && j < B -> length){
        k++;

        if (A -> data[i] < B -> data[j]){
            if (k == A -> length)
                return A -> data[i];
            i++;
        } else {
            if (k == B -> length)
                return B -> data[j];
            j++;
        }
    }
}

int main (){
    SqList *L1 = init();
    SqList *L2 = init();
    ListInsert(L1, 3);
    ListInsert(L1, 2);
    ListInsert(L1, 9);
    ListInsert(L1, 6);
    DispList(L1);
    ListInsert(L2, 2);
    ListInsert(L2, 7);
    ListInsert(L2, 5);
    ListInsert(L2, 4);
    DispList(L2);
    SqList *L;
    UnionList(L1, L2, L);
    DispList(L);
    cout << M_Search(L1, L2) << endl;
}