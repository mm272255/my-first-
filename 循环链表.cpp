#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
//typedef struct LNode{
//	ElemType data;
//	struct LNode*next;
//}LinkNode;
//void CreateList(LinkNode*&L,ElemType a[],int n){
//	LinkNode*s,*r=NULL;
//	L=(LinkNode*)malloc(sizeof(LinkNode));
//	L->next=NULL;
//	for(int i=0;i<n;++i){
//		s=(LinkNode*)malloc(sizeof(LinkNode));
//		s->data=a[i];
//		s->next=L->next;
//		L->next=s;
//		if(i==0) r=s;
//	}
//	if(r!=NULL) r->next=L;
//}
//void InitList(LinkNode*&L){
//	L=(LinkNode*)malloc(sizeof(LinkNode));
//	L->next=NULL;
//}
//void DispList(LinkNode*L){
//	LinkNode*p=L->next;
//	while(p!=L){
//		cout<<p->data<<" ";
//		p=p->next;
//	}
//	cout<<endl;
//}



//在一个带头结点的循环单链表中统计其data域值为x的结点的次数
//int count(LinkNode*L,ElemType x){
//	int cnt=0;
//	LinkNode*p=L->next;
//	while(p!=L){
//		if(p->data==x){
//		cnt++;
//		}
//		p=p->next;
//	}
//	return cnt;
//}
//int main(){
//	LinkNode* L; 
//	int b[]={2,3,4,3,6,7};
//	int n=sizeof(b)/sizeof(b[0]);
//	CreateList(L,b,n);
//	DispList(L);
//	int e=count(L,3);
//	cout<<e<<endl;
//}

typedef struct DLNode{
	ElemType data;
	struct DLNode*prior;
	struct DLNode*next;
}DLinkNode;
void InitList(DLinkNode*&L){
	L=(DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior=L->next=L;
}
void CreateList(DLinkNode*&L,ElemType a[],int n){
	DLinkNode*s;
	InitList(L);
	for(int i=0;i<n;++i){
		s=(DLinkNode*)malloc(sizeof(DLinkNode));
		s->data=a[i];
		s->next=L->next;
		L->next->prior=s;
		L->next=s;
		s->prior=L;
	}
}
void DispList(DLinkNode*L){
	DLinkNode*p=L->next;
	while(p!=L){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
//判断一个带头结点的循环双链表（含两个以上结点）中的数结点是否对称
bool Symm(DLinkNode*L){
	bool same=true;
	DLinkNode*p=L->next;
	DLinkNode*q=L->prior;
	while(same){
		if(p->data!=q->data){
			same=false;
		}else{
			if(p==q||p->next==q){
				break;
			}else{
				p=p->next;
				q=q->prior;
			}
		}
	}
	return same;
}
int main(){
	DLinkNode* L; 
	int b[]={2,3,4,3,6,7};
	int n=sizeof(b)/sizeof(b[0]);
	CreateList(L,b,n);
	DispList(L);
	if(Symm(L)){
		cout<<"对称"<<endl;
	}else{
		cout<<"不对称"<<endl;
	}
}
//在一个带头结点的循环双链表中删除第一个data域值为x的结点
//bool delelem(DLinkNode*&L,ElemType e){
//	DLinkNode*p=L->next;
//	while(p!=L&&p->data!=e){
//		p=p->next;
//	}
//		if(p!=L){
//			p->next->prior=p->prior;
//			p->prior->next=p->next;
//			free(p);
//			return true;
//		}else{
//			return false;
//		}
//}
//int main(){
//	DLinkNode* L; 
//	int b[]={2,3,4,3,6,7};
//	int n=sizeof(b)/sizeof(b[0]);
//	CreateList(L,b,n);
//	DispList(L);
//	delelem(L,3);
//	DispList(L);
//}
