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
void delnode2(SqList*&L,int x){
	int k=0;
	for(int i=0;i<L->length;++i){
		if(L->data[i]==x){
			k++;
		}else{
			L->data[i-k]=L->data[i];
		}
	}
	L->length-=k;
}
int main(){
	SqList*L;
	int deleteVal,n;
	IniList(L);
	cout<<"请输入顺序表的元素个数（不超过"<<Maxsize<<"):";
	cin>>n;
	if(n>0&&n<=Maxsize){
		cout<<"请输入"<<n<<"个整数:";
		for(int i=0;i<n;++i){
			cin>>L->data[i];
		}
		L->length=n;
	}else{
		cout<<"元素输入失败"<<endl;
	}
	cout << "\n删除前的顺序表：";
	DispList(L);
	cout<<"输入要删除的元素：";
	cin>>deleteVal;
	delnode2(L,deleteVal);
	cout << "删除后的顺序表：";
	DispList(L);
	free(L);
	L=NULL;
	
}
