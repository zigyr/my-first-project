#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

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
    return 0;
}

//ListInsert
void ListInsert(SeqList *L, int pos, ElemType e){
    for(int i = L -> len; i >= pos - 1; i--){
        L -> data[i] = L -> data[i - 1];
    }
    L -> data[pos - 1] = e;
    L -> len++;
}

//ListDelete
void ListDelete(SeqList *L, int pos, ElemType *e){
    *e = L -> data[--pos];
    for (int i = pos; i < L -> len - 1; i++){
        L -> data[i] = L -> data[i + 1];
    }
    L -> len--;
}

//endInsert
void EndInsert(SeqList *L,ElemType e){
	if(L->len>=MAXSIZE){
		printf("[endInsert]full\n");
	}
	L->data[L->len++]=e;
}

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

int main() {
    //L->data = malloc(...) 只是让 data 指针指向了一段动态分配的内存，
    //但 sizeof(data) 永远只计算指针本身的字节数，
    //和它指向的内存大小（sizeof(ElemType)*MAXSIZE）无关


    //init-check
    SeqList *list = initList();
    printf("%d\n", list->len);
    printf("%lld\n", sizeof(list->data));

    EndInsert(list, 1);
    EndInsert(list, 2);
    EndInsert(list, 3);
    EndInsert(list, 4);
    EndInsert(list, 10);
    EndInsert(list, 5);
    EndInsert(list, 10);
    EndInsert(list, 6);
    DispList(list);
    delnode1(list, 10);
    DispList(list);


}