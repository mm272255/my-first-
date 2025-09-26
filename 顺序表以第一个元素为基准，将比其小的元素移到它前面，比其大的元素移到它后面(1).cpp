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
int partitionl(SqList*&L){
	int i=0,j=L->length-1;
	int base=L->data[0];
	while(i<j){
		while(i<j&&L->data[j]>base){
			j--;
		}
		while(i<j&&L->data[i]<=base){
			i++;
		}
		if(i<j){
			swap(L->data[i],L->data[j]);
		}
	}
	swap(L->data[0],L->data[i]);
}
int main(){
	SqList*L;
	IniList(L);
	int b[]={4,2,1,3,6,8,7,10,5};
	int n=sizeof(b)/sizeof(b[0]);
	CreateList(L,b,n);
	DispList(L);
	partitionl(L);
	DispList(L);
}
