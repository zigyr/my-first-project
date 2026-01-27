//单链表
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

//动态初始化
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
//头插法
void insertHead(Node *L,ElemType e){
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=e;
	temp->next=L->next;
	L->next=temp;
	return;
}
//尾插法
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
	tail->next=p;
	p->next=NULL;	
	return p;
}
//遍历链表元素
void listNode(Node *L){
	Node *p=L->next;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
} 
//任意位置插入元素
int insertNode(Node* L,int pos,ElemType e){
	Node *p=L;
	for(int i=0;i<pos-1;i++){
		p=p->next;
		if(p->next==NULL){
			printf("输入位置错误\n");
			return 0; 
		}
	} 
	Node *q=(Node*)malloc(sizeof(Node));
	q->data=e;
	q->next=p->next;
	p->next=q;
	return 1;
}
//删除任意位置元素
int deleNode(Node *L,int pos){
	Node *p=L;
	for(int i=0;i<pos-1;i++){
		p=p->next;
		if(p->next==NULL){
			return 0;
		}
	}
	Node *temp;
	temp=p->next;
	p->next=temp->next;
	free(temp);
} 
//获取链表长度
int listLength(Node *L){
	int i=0;
	while(L->next!=NULL){
		i++;
		L=L->next;
	}
	return i;
} 
//释放链表
int freeList(Node *L){
	Node *temp;
	Node *p=L->next;
	while(p!=NULL){
		temp=p->next;
		free(p);
		p=temp;
	}
	L->next=NULL;
	return 1;
} 
//倒数第k的节点
void findNode(Node *L,int k){
	Node *fast=L->next;
	Node *slow=L->next;
	for(int i=0;i<k;i++)fast=fast->next;
	while(fast!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	printf("碌鹿脢媒碌脷%d赂枚脦禄脰脙碌脛脭陋脣脴脢脟:%d",k,slow->data);
}
//链表str1"loading"与str2"being"后缀相同部分的其实节点
Node* findIntersectionNode(Node *headA,Node *headB){
	int lenA=0,lenB=0;
	Node *p,*q;
	while(p->next!=NULL){
		lenA++;
		p=p->next;
	}
	while(q->next!=NULL){
		lenB++;
		q=q->next;
	}
	int step=0;
	Node *fast,*slow;
	if(lenA>lenB){
		step=lenA-lenB;
		fast=headA;
		slow=headB;
	}else{
		step=lenB-lenA;
		fast=headB;
		slow=headA;
	}
	for(int i=0;i<step;i++)fast=fast->next;
	while(fast!=slow){
		fast=fast->next;
		slow=slow->next;
	}
	return fast;
}
//删除链表元素绝对值相同的第一个元素
void removeNode(Node *L,int n){
	Node *p=L;
	int *q=(int*)calloc(n+1,sizeof(int));
	while(p->next!=NULL||p!=NULL){
		int num=abs(p->next->data);
		if(*(q+num)==0){
			*(q+num)=1;
			p=p->next;
		}else{
			Node *temp=p->next;
			p->next=temp->next;
			free(temp);
		}
	}
	free(q);
}
//反转链表
Node* reverseList(Node *head){
	Node *first=head;
	Node *second=head->next;
	Node *third=NULL;//初始化为空指针，安全性高于'NOde *third;'
	while(second!=NULL){
		third=second->next;
		second->next=first;
		first=second;
		second=third;
	}
	Node *q=initList();
	q->next=first;
}
//删除链表中间节点
int delMiddlleNode(Node *head){
	Node *fast=head->next;
	Node *slow=head;
	while(fast->next!=NULL||fast!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	Node *temp=slow->next;
	slow->next=temp->next;
	free(temp);
	return 1;
}
//将链表L0=(a1,a2,a3,···，an-1,an)转变为L1=(a1,an,a2,an-1,a3···)
void reOrderList(Node *head){
	Node *fast=head->next;
	Node *slow=head;
	while(fast!=NULL||fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	Node *first=NULL,*second=slow->next,*third=NULL;
	slow->next=NULL;
	while(second!=NULL){
		third=second->next;
		second->next=first;
		first=second;
		second=third;
	}
	Node *p1=head->next,*q1=first;
	Node *p2,*q2;
	while(p1!=NULL&&q1!=NULL){
		p2=p1->next;
		q2=q1->next;
		p1->next=q1;
		q1->next=p2;
		p1=p2;q1=q2;
	}
}
//判断链表是否有环
int isCycle(Node *head){
	Node *fast=head;
	Node *slow=head;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;//当使用快慢指针如fast=fast->next->next时，fast!=NULL&&fast->next!=NULL是搭配的
		slow=slow->next;
		if(slow==fast){
			return 1;
		}
	}
	return 0;
}
//链表有环，那入口在哪里
 Node *findBegin(Node *head){
 	Node *fast=head;
 	Node *slow=head;
 	while(fast!=NULL&&fast->next!=NULL){
 		fast=fast->next->next;
 		slow=slow->next;
 		if(slow==fast){
 			int cound=1;
 			while(fast!=slow){
 				fast=fast->next;
 				cound++;
 			}
 			fast=head;
 			slow=head;
 			for(int i=0;i<cound;i++){
 				fast=fast->next;
 			}
 			while(slow!=fast){
 				fast=fast->next;
 				slow=slow->next;
 			}
 			return slow;
 		}
 	}
 	return NULL;
 }
int main (){
	Node *list=initList();
	insertHead(list,1);
	insertHead(list,2);
	insertHead(list,3);
	insertHead(list,4);
	Node *tail=get_tail(list);
	tail=insertTail(tail,1);
	tail=insertTail(tail,1);
	insertNode(list,3,5);
	// deleNode(list,3);
	listNode(list); 
	// freeList(list);
	// int length=listLength(list);
	// printf("%d",length);
	// findNode(list,6);
/**	
	Node *headA=initList();
	Node *headB=initList();
	Node *a1=(Node*)malloc(sizeof(Node));
	Node *a2=(Node*)malloc(sizeof(Node));
	Node *a3=(Node*)malloc(sizeof(Node));
	a1->data=1;
	a2->data=2;
	a3->data=3;
	a3->next=NULL;
	Node *tailA,*tailB;
	tailA=get_tail(headA);
	tailB=get_tail(headB);
	tailA=insertTail(tailA,7); 
	tailA=insertTail(tailA,8);
	tailA=insertTail(tailA,9);
	tailA=insertTail(tailA,4);
	tailB=insertTail(tailB,5);
	tailB=insertTail(tailB,6);
	tailA->next=a1;
	tailB->next=a1;
	listNode(headA);
	Node *p=findIntersection(headA,headB);
	printf("虏芒脢脭%d",p->data);
**/
	            
	return 0;
}


