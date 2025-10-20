#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
#define MaxCol 10
typedef struct Node1{
	ElemType data[MaxCol];
	struct Node1*next;
}DList;
typedef struct Node2{
	int Row,Col;
	DList*next;
}HList;
void CreateTable(HList*&h){
	DList*r,*s;
	h=(HList*)malloc(sizeof(HList));
	cout<<"表的行数，列数：";
	cin>>h->Row>>h->Col;
	for(int i=0;i<h->Row;++i){
		cout<<"第"<<i+1<<"行";
		s=(DList*)malloc(sizeof(DList));
		for(int j=0;j<h->Col;++j){
			cin>>s->data[j];
		}
		if(h->next==NULL){
			h->next=s;
		}else{
			r->next=s;
		}
		r=s;
	}
	r->next=NULL;
	
}
void DestroyTable(HList*&h){
	DList*pre=h->next,*p=pre->next;
	while(p!=NULL){
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
	free(h);
}
void DispTable(HList*h){
	DList*p=h->next;
	while(p!=NULL){
		for(int j=0;j<h->Col;++j){
			cout<<p->data[j]<<" ";
		}
		cout<<endl;
		p=p->next;
	}
}
void LinkTable(HList*h1,HList*h2,HList*&h){
	int i,j;
	DList*p=h1->next,*q,*r,*s;
	cout<<"连接字段是：第一个表序号，第二个表序号：";
	cin>>i>>j;
	h=(HList*)malloc(sizeof(HList));
	h->Row=0;
	h->Col=h1->Col+h2->Col;
	h->next=NULL;
	while(p!=NULL){
		q=h2->next;
	while(q!=NULL){
		if(p->data[i-1]==q->data[j-1]){
			s=(DList*)malloc(sizeof(DList));
			for(int k=0;k<h1->Col;++k){
				s->data[k]=p->data[k];
			}
			for(int k=0;k<h2->Col;++k){
				s->data[h1->Col+k]=q->data[k];
			}
			if(h->next==NULL){
				h->next=s;
			}else{
				r->next=s;
			}
			r=s;
			h->Row++;
		}
		q=q->next;
	}
		p=p->next;
	}
	r->next=NULL;
}
  
int main(){
	HList*h1,*h2,*h;
	cout<<"表1：";
	CreateTable(h1);
	cout<<"表2：";
	CreateTable(h2);
	LinkTable(h1,h2,h);
	cout<<"连接结果表：";
	DispTable(h);
	DestroyTable(h1);
	DestroyTable(h2);
	DestroyTable(h);
	
	
}
