#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

// 交换函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef int ElemType;

// initList
// // static
// typedef struct{
// 	ElemType data[MAXSIZE];
// 	int len;
// }SeqList;
// void initList(SeqList *L){
// 	L->len=0;
// }
// dynamic
typedef struct{
	ElemType *data;
	int len;
}SeqList;
SeqList* initList(){
	SeqList *L = (SeqList*)malloc(sizeof(SeqList));
	L->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	L->len = 0;
	return L;
}

//DestroyList
void DestoryList(SeqList *L){
    free(L);
}

//ListEmpty
int ListEmpty(SeqList *L){
    return L->len == 0;
}

//ListLength
int ListLength(SeqList *L){
    return L -> len;
}

//DispList
void DispList(SeqList *L) {
    for (int i = 0; i < L->len;) {
        printf("%d ", L->data[i++]);
    }
    printf("\n");
}

//GetElem
void GetElem(SeqList *L, int i, ElemType *e){
    *e = L -> data[i - 1];
}

//LocateElem
int LocateElem(SeqList *L, ElemType e){
    for (int i = 0;i < L -> len; i++){
        if (L -> data[i] == e) return i + 1;
    }
    return -1;
}

//ListInsert
void ListInsert(SeqList *L, int pos, ElemType e){
    // 把一个数，插入最后一个数的前面，显然是合法的
    // 但是把一个数，插入到最后一个数的后面，仍然是合法的
    if (pos < 1 || pos > L -> len + 1){
        printf("[ListInsert]position error\n");
    }
    for(int i = L -> len; i >= pos; i--){
        L -> data[i] = L -> data[i - 1];
    }
    L -> data[pos - 1] = e;
    L -> len++;
}
//ListDelete
void ListDelete(SeqList *L, int pos, ElemType *e){
    for (int i = pos; i < L -> len; i++){
        L -> data[i - 1] = L -> data[i];
    }
    *e = L -> data[pos - 1];
    L -> len--;
}
//endInsert
void EndInsert(SeqList *L,ElemType e){
	if(L->len>=MAXSIZE){
		printf("[endInsert]full\n");
	}
	L->data[L->len++]=e;
}

/*
P38
实现删除所有值等于x的元素
*/
//delnode1
void delnode1(SeqList *L, ElemType e){
    int i = 0, k = 0;
    for (; i < L -> len; i++){
        if (L -> data[i] != e){
            L -> data[k++] = L -> data[i];
        }
    }
    L -> len = k;
}
//delnode2
void delnode2(SeqList *L, ElemType e){
    int i = 0, k = 0;
    while(i < L -> len){
        if (L -> data[i] == e) k++; 
        else L -> data[i - k] = L -> data[i];
        i++;
    }
    L -> len -= k;
}

/*
P39
实现数组的排序, 
以第一个元素为基准, 将所有小于或等于基准的数移前, 将所有大于基准的数移后
*/
void partition1(SeqList *L){
    int i = 0, j = L -> len - 1;
    ElemType base = L -> data[0];
    while(i < j){
        while (i < j && L -> data[j] > base) j--;
        while (i < j && L -> data[i] <= base) i++;
        swap(&L -> data[i], &L -> data[j]);
    }
    swap(&L -> data[0], &L -> data[i]);
}
void partition2(SeqList *L){
    int i = 0, j = L -> len - 1;
    ElemType base = L -> data[0];
    while(i < j){
        while (i < j && L -> data[j] > base) j--;
        L -> data[i] = L -> data[j];
        while (i < j && L -> data[i] <= base) i++;
        L -> data[j] = L -> data[i];
    }
    L -> data[i] = base;
}

/*
P41
将所有的奇数移动到偶数之前
*/
void move1(SeqList *L){
    int i = 0, j = L -> len -1;
    while(i < j){
        while(i < j && L -> data[j] % 2 == 0) j--;
        while(i < j && L -> data[i] % 2 != 0) i++;
        swap(&L -> data[j], &L -> data[i]);
    }
}
void move2(SeqList *L){
    int i = -1;
    for (int j = 0; j < L -> len; j++){
        if (L -> data[j] % 2 != 0){
            i++;
            swap(&L -> data[j], &L -> data[i]);
        }
    }
}

int main() {
    //L->data = malloc(...) 只是让 data 指针指向了一段动态分配的内存，
    //但 sizeof(data) 永远只计算指针本身的字节数，
    //和它指向的内存大小（sizeof(ElemType)*MAXSIZE）无关


    // SeqList list;
    // initList(&list);
    SeqList *list = initList();
    printf("%d\n", list->len);
    printf("%lld\n", sizeof(list->data));

    EndInsert(list, 4);
    EndInsert(list, 1);
    EndInsert(list, 0);
    EndInsert(list, 7);
    EndInsert(list, 9);
    EndInsert(list, 10);
    EndInsert(list, 2);
    EndInsert(list, 3);
    DispList(list);
    delnode1(list, 10);
    DispList(list);
    ListInsert(list, 2, 20);
    DispList(list);
    int e;
    ListDelete(list, 2, &e);
    DispList(list);
    partition2(list);
    DispList(list);
    move2(list);
    DispList(list);

}