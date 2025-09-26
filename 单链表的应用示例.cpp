#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType ;
typedef struct LNode{
	ElemType data;
	struct LNode*next;
}LinkNode;
void InitList(LinkNode*&L){
	L=(LinkNode*)malloc(sizeof(LinkNode));
	L->next=NULL;
}
void DispList(LinkNode*L){
	LinkNode*p=L->next;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
void CreateList(LinkNode*&L,ElemType b[],int n){
	LinkNode*s,*r;
	L=(LinkNode*)malloc(sizeof(LinkNode));
	r=L;
	for(int i=0;i<n;++i){
		s=(LinkNode*)malloc(sizeof(LinkNode));
		s->data=b[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}
//设计一个带头结点的单链表所有数据节点按data域递增排序

void sort(LinkNode*&L){
	LinkNode*p,*pre,*q;
	p=L->next->next;
	L->next->next=NULL;
	while(p!=NULL){
		q=p->next;
		pre=L;
		while(pre->next!=NULL&&pre->next->data<p->data){
			pre=pre->next;
		}
		p->next=pre->next;
		pre->next=p;
		p=q;
	}
}

int main(){
	LinkNode*L;
	InitList(L);
	int a[]={5,4,3,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	cout<<"排序前的链表：";
	DispList(L);
	sort(L);
	cout<<"排序后的链表：";
	DispList(L);
}
//设计实现一个带头结点的单链表被拆分成两个单链表，L1实现奇数点正序排列，L2实现偶数点逆序排列

//void split(LinkNode*&L,LinkNode*&L1,LinkNode*&L2){
//	LinkNode*p=L->next,*q,*r1;
//	L1=L;
//	r1=L1;
//	L2=(LinkNode*)malloc(sizeof(LinkNode));
//	L2->next=NULL;
//	while(p!=NULL){
//		r1->next=p;
//		r1=p;
//		p=p->next;
//		if(p==NULL) break;
//		q=p->next;
//		p->next=L2->next;
//		L2->next=p;
//		p=q;
//	}
//	r1->next=NULL;
//}

//int main(){
//	LinkNode*L,*L1,*L2;
//	InitList(L);
//	int a[]={1,2,3,4,5};
//	int n=sizeof(a)/sizeof(a[0]);
//	CreateList(L,a,n);
//	cout<<"拆分前的原链表：";
//	DispList(L);
//	split(L,L1,L2);
//	cout<<"拆分后的L1:";
//	DispList(L1);
//	cout<<"拆分后的L2:";
//	DispList(L2);
//	
//	
//}
//删除一个单链表中元素值最大的结点

//void delmaxnode(LinkNode*&L){
//	LinkNode*p=L->next,*pre=L,*maxp=p,*maxpre=pre;
//	while(p!=NULL){
//		if(maxp->data<p->data){
//			maxp=p;
//			maxpre=pre;
//		}
//		pre=p;
//		p=p->next;
//	}
//	maxpre->next=maxp->next;
//	free(maxp);
//}
//
//int main(){
//	LinkNode*L;
//	InitList(L);
//	int a[]={1,2,3,4,5};
//	int n=sizeof(a)/sizeof(a[0]);
//	CreateList(L,a,n);
//	cout<<"找出最大元素值并删除前的链表：";
//	DispList(L);
//	delmaxnode(L);
//	cout<<"找出最大元素值并删除后的链表：";
//	DispList(L);
//	
//}


