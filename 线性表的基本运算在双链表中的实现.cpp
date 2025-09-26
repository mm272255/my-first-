#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
typedef struct DNode{
	ElemType data;
	struct DNode*prior;
	struct DNode*next;
}DLinkNode;

//头插法
//void CreateList(DLinkNode*&L,ElemType a[],int n){
//	DLinkNode*s;
//	L=(DLinkNode*)malloc(sizeof(DLinkNode));
//	L->prior=L->next=NULL;
//	for(int i=0;i<n;++i){
//		s=(DLinkNode*)malloc(sizeof(DLinkNode));
//		s->data=a[i];
//		s->next=L->next;
//		if(L->next!=NULL){
//			L->next->prior=s;
//		}
//		L->next=s;
//		s->prior=L;
//	}
//}

//尾插法
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
//求长度
int LengthList(DLinkNode*L){
	int n=0;
	DLinkNode*p=L;
	while(p->next!=NULL){
		n++;
		p=p->next;
	}
	return n;
}
bool ListEmpty(DLinkNode*L){
	return (L->next==NULL);
}
void InitList(DLinkNode*&L){
	L=(DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior=L->next=NULL;
}
void DestroyList(DLinkNode*&L){
	DLinkNode*pre=L,*p=L->next;
	while(p!=NULL){
		free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);
}
bool GetElem(DLinkNode*L,int i,ElemType &e){
	int j=1;
	DLinkNode*p=L->next;
	if(i<=0) return false;
	while(j<i&&p!=NULL){
		j++;
		p=p->next;
	}
	if(p==NULL){return false;}
	else{
		e=p->data;
		return true;
	} 
}
int LocateElem(DLinkNode*L,ElemType e){
	int i=1;
	DLinkNode*p=L->next;
	while(p!=NULL&&p->data!=e){
		i++;
		p=p->next;
	}
	if(p==NULL){
		return false;
	}else{
		return i;
	}
}
bool ListInsert(DLinkNode*&L,int i,ElemType e){
	int j=0;
	DLinkNode*p=L,*s;
	if(i<=0) return false;
	while(j<i-1&&p!=NULL){
		j++;
		p=p->next;
	}
	if(p==NULL){
		return false;
	}else{
		s=(DLinkNode*)malloc(sizeof(DLinkNode));
		s->data=e;
		s->next=p->next;
		if(p->next!=NULL){
			p->next->prior=s;
		}
		p->next=s;
		s->prior=p;
		return true;
	}
}
bool ListDelete(DLinkNode*&L,int i,ElemType &e){
	int j=0;
	DLinkNode*p=L,*q;
	if(i<=0) return false;
	while(j<i-1&&p!=NULL){
		j++;
		p=p->next;
	}
	if(p==NULL){
		return false;
	} else{
		q=p->next;
		if(q==NULL){
			return false;
		}
		e=q->data;
		p->next=q->next;
		if(q->next!=NULL){
			q->next->prior=p;
			free(q);
			return true;
		}
	}
}

int main(){
	DLinkNode*L;
	int b[]={2,3,4,5,6,7};
	int n=sizeof(b)/sizeof(b[0]);
	CreateListR(L,b,n);
	DispList(L);
	cout<<LengthList(L)<<endl;
	if(ListEmpty(L)){
		cout<<"空"<<endl;
	} else{
		cout<<"不为空"<<endl;
	}
	int getelem;
	if(GetElem(L,3,getelem)){
		cout<<"位置3的元素："<<getelem<<endl;
	}else{
		cout<<"位置3的元素获取失败"<<endl;
	}
	cout<<"LocateElem:"<<endl;
	int l=LocateElem(L,4);
	if(l!=0){
		cout<<"元素4的位置:"<<l<<endl;
	}else{
		cout<<"未找到元素4"<<endl;
	}
	cout<<"ListInsert:"<<endl;
	for(int i=1;i<=5;++i){
		if(ListInsert(L,i,i*10)){
			cout<<"在位置"<<i<<"插入"<<i*10<<endl;
		}else{
			cout<<"在位置"<<i<<"插入"<<i*10<<"失败"<<endl;
		}
	}
	bool flag;
	ElemType e;
	cout << "删除前链表：";
	DispList(L);  // 插入后：5 11 22 30 33 44 55 66 70
	// 测试1：合法删除（头部1、中间5、尾部9）
	flag = ListDelete(L, 1, e);  // 删头部5
	cout << "删除第1位：" << (flag ? ("成功，被删值：" + to_string(e)) : "失败") << endl;  // 预期：5
	flag = ListDelete(L, 5, e);  // 删第5位（当前第5位是44）
	cout << "删除第5位：" << (flag ? ("成功，被删值：" + to_string(e)) : "失败") << endl;  // 预期：44
	DestroyList(L);
}
