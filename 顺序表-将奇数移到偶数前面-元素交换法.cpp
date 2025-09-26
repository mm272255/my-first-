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
void CreateList(SqList * &L,int a[],int n){
	int i=0,k=0;
	L=(SqList*)malloc(sizeof(SqList));
	while(i<n){
		L->data[i]=a[i];
		k++,i++;
	}
	L->length=k;
}
void movel(SqList*&L){
	int i=0,j=L->length-1;
	while(i<j){
		while(j>i&&L->data[j]%2==0){
			j--;
		}
		while(i<j&&L->data[i]%2!=0){
			i++;
		}
		if(i<j){
			swap(L->data[i],L->data[j]);
		}
	}
}
int main(){
	SqList*L;
	int b[]={1,4,3,6,7,2,9,8};
	int n=sizeof(b)/sizeof(b[0]);
	IniList(L);
	CreateList(L,b,n);
	DispList(L);
	movel(L);
	DispList(L);
}
