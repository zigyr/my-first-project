#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

typedef int ElemType;

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
	SeqList *L=(SeqList*)malloc(sizeof(SeqList));
	L->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	L->len=0;
	return L;
}

//endinsert
int endinsert(SeqList *L,ElemType e){
	if(L->len>=MAXSIZE){
		printf("full\n");
		return 0;
	}
	L->data[L->len++]=e;
}

//list
void listElem(SeqList *L) {
    if (L->len==0) {
        printf("empty\n");
        return;
    }
    int i = 0;
    while (i < L->len) {
        printf("%d ", L->data[i++]);
    }
    printf("\n");
}

//insert
int insertElem(SeqList *L,int pos,ElemType e){
    if(L->len>=MAXSIZE){
		printf("full\n");
		return 0;
	}
    if(pos<1||pos>L->len){
        printf("incorrect\n");
        return 0;
    }
    for(int i=L->len-1;i>=pos-1;i--){
        L->data[i+1]=L->data[i];
    }
    L->data[pos-1]=e;
    L->len++;
    return 1;
}

//delete
int deleteElem(SeqList *L,int pos,ElemType *e){
    if(L->len==0){
        printf("empty\n");
        return 0;
    }
    if(pos<1||pos>L->len){
        printf("incorrect\n");
        return 0;
    }
    *e=L->data[pos-1];
    for(int i=pos;i<=L->len-1;i++){
        L->data[i-1]=L->data[i];
    }
    L->len--;
    return 1;
}

//search
int findElem(SeqList *L,ElemType e){
    if(L->len==0){
        printf("empty\n");
        return 0;
    }
    for(int i=0;i<L->len;i++){
        if(L->data[i]==e)return i+1;
    }
    printf("%d is non-existent\n",e);
    return 0;
}

int main() {
    //init-check
    SeqList *list = initList();
    printf("%d\n", list->len);
    printf("%lld\n", sizeof(list->data));
    //L->data = malloc(...) 只是让 data 指针指向了一段动态分配的内存，
    //但 sizeof(data) 永远只计算指针本身的字节数，
    //和它指向的内存大小（sizeof(ElemType)*MAXSIZE）无关
    //endinsert-check
    endinsert(list, 1);
    endinsert(list, 2);
    endinsert(list, 3);
    insertElem(list,1,10);
    printf("%lld\n", sizeof(list->data));
    //findElem-check
    printf("%d\n",findElem(list,10));
    //listElem-check
    listElem(list);
    //deleteElem-check
    int e;
    deleteElem(list,1,&e);
    listElem(list);
    findElem(list,10);
    printf("%d\n",e);
    free(list->data);
    free(list);
}