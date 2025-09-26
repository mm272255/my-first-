#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode*prior;
	struct DNode*next;
}DLinkNode;
void CreateListR(DLinkNode*&L,ElemType a[],int n){
	DLinkNode*s,*r;
	L=(DLinkNode*)malloc(sizeof(DLinkNode));
	r=L;
	for(int i=0;i<n;++i){
		s=(DLinkNode*)malloc(sizeof(DLinkNode));
		s->data=a[i];
		r->next=s;
		s->prior=r;
		r=s;
	}
	r->next=NULL;
}
void DispList(DLinkNode*L){
	DLinkNode*p=L->next;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void InitList(DLinkNode*&L){
	L=(DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior=L->next=NULL;
}
//设计一个带头结点的单链表所有数据节点按data域递增排序
void sort(DLinkNode*&L){
	DLinkNode*p=L->next->next,*q,*pre;
	L->next->next=NULL;
	while(p!=NULL){
		pre=L;
		q=p->next;
	while(pre->next!=NULL&&pre->next->data<p->data){
		pre=pre->next;
	}
		p->next=pre->next;
		if(pre->next!=NULL){
			pre->next->prior=p;
		}
		p->prior=pre;
		pre->next=p;
		p=q;
	}
}

int main(){
	DLinkNode*L;
	int c[]={1,5,3,0,2,6,4};
	int n=sizeof(c)/sizeof(c[0]);
	CreateListR(L,c,n);
	DispList(L);
	sort(L);
	DispList(L);
}
//将双链表转置
//void reverse(DLinkNode*&L){
//	DLinkNode*p=L->next,*q;
//	L->next=NULL;
//	while(p!=NULL){
//		q=p->next;
//		p->next=L->next;
//		if(L->next!=NULL){
//			L->next->prior=p;
//		}
//		p->prior=L;
//		L->next=p;
//		p=q;
//	}
//}
//int main(){
//	DLinkNode*L;
//	int b[]={2,3,4,5,6,7};
//	int n=sizeof(b)/sizeof(b[0]);
//	CreateListR(L,b,n);
//	DispList(L);
//	reverse(L);
//	DispList(L);
//}
