#include<iostream>
#include<stdlib.h>
using namespace std;
#define Maxsize 100
typedef struct S{
	int data[Maxsize];
	int length;
}SqList;
void IniList(SqList*&L){
	L=(SqList*)malloc(sizeof(SqList));
	L->length=0;
}
void DispList(SqList*L){
	for(int i=0;i<L->length;++i){
		cout<<L->data[i]<<" ";
	}
	cout<<endl;
}
void CreateList(SqList*&L,int a[],int n){
	int k=0;
	L=(SqList*)malloc(sizeof(SqList));
	for(int i=0;i<n;++i){
		L->data[k]=a[i];
		k++;
	}
	L->length=k;
}
void partitionl2(SqList*&L){
	int i=0,j=L->length-1;
	int base=L->data[0];
	while(i<j){
	while(j>i&&L->data[j]>base){
		j--;
	}
		L->data[i]=L->data[j];
	while(i<j&&L->data[i]<=base){
		i++;
	}
		L->data[j]=L->data[i];
	}
	L->data[i]=base;
}
int main(){
	SqList*L;
	IniList(L);
	int b[]={3,8,2,7,1,5,3,4,6,0};
	int n=sizeof(b)/sizeof(b[0]);
	CreateList(L,b,n);
	DispList(L);
	partitionl2(L);
	DispList(L);
}
