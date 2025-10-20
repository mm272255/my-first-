#include<iostream>
#include<stdlib.h>
using namespace std;
#define Maxsize 100
typedef int ElemType;
typedef struct S{
	ElemType data[Maxsize];
	int length;
}SqList;
void CreateList(SqList * &L,ElemType a[],int n){
	int i=0,k=0;
	L=(SqList*)malloc(sizeof(SqList));
	while(i<n){
		L->data[i]=a[i];
		k++,i++;
	}
	L->length=k;
}
void IniList(SqList * &L){
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
void DestroyList(SqList*&L){
	free(L);
}
bool ListEmpty(SqList*&L){
	return (L->length==0);
}
int ListLength(SqList*&L){
	return (L->length);
}
void DispList(SqList*L){
	for(int i=0;i<L->length;++i){
		printf("%d",L->data[i]);
		printf("\n");
	}
}
bool GetElem(SqList*&L,int i,int &e){
	if(i<1||i>L->length){
		return false;
	}
	e=L->data[i-1];
	return true;
}
int LocateElem(SqList*L,int e){
	for(int i=0;i<L->length;++i){
		if(L->data[i]==e){
			return (i+1);
		}
	}
	return 0;
}
void ListInsert(SqList*&L,int e){
	int i=0,j;
	while(i<L->length&&L->data[i]<e){
		i++;
	}
	for(j=ListLength(L);j>i;j--){
			L->data[j]=L->data[j-1];
	}
	L->data[i]=e;
	L->length++;
}
bool ListDelete(SqList*&L,int i,int& e){
	if(i<1||i>L->length){
		return false;
	}
	i--;
	e=L->data[i];
	for(int j=i;j<L->length;++j){
		L->data[j]=L->data[j+1];
	}
	L->length--;
	return true;
}
int main(){
	SqList*L=NULL;
	cout<<"InitList:"<<endl;
	IniList(L);
	cout<<L->length<<endl;
	cout<<"Empty:"<<endl;
	if(ListEmpty(L)){
		cout<<"空"<<endl;
	} else{
		cout<<"不为空"<<endl;
	}
	cout<<"ListInsert:"<<endl;
	ListInsert(L,10);
	DispList(L);
	cout<<"DispList:"<<endl;
	DispList(L);
	cout<<"ListLength:"<<endl;
	cout<<ListLength(L)<<endl;
	cout<<"GetElem:"<<endl;
	int getelem;
	if(GetElem(L,3,getelem)){
		cout<<"位置3的元素："<<getelem<<endl;
	}else{
		cout<<"位置3的元素获取失败"<<endl;
	}
	cout<<"LocateElem:"<<endl;
	int l=LocateElem(L,20);
	if(l!=0){
		cout<<"元素20的位置:"<<l<<endl;
	}else{
		cout<<"未找到元素20"<<endl;
	}
	cout<<"ListDelete:"<<endl;
	int d;
	if(ListDelete(L,3,d)){
		cout<<"删除位置3的元素成功"<<endl;
	}else{
		cout<<"删除位置3的元素不成功"<<endl;
	}
	cout<<"DispList:"<<endl;
	DispList(L);
	cout<<"CreateList:"<<endl;
	int b[]={100,200,300,400,500};
	int n=sizeof(b)/sizeof(b[0]);
	SqList*L2=NULL;
	CreateList(L2,b,n);
	DispList(L2);
	cout<<"DestroyList:"<<endl;
	DestroyList(L2);
	DestroyList(L);
	
	
}
//单链表插入
//void ListInsert(LinkNode*&L,ElemType e){
//	LinkNode*pre=L,*p;
//	while(pre->next!=NULL&&pre->next->data<e)
//		pre=pre->next;
//	p=sizeof(LinkNode*)malloc(LinkNode);
//	p->data=e;
//	p->next=pre->next;
//	pre->next=p;
//}

//顺序表二路归并
void UnionList(SqList *LA, SqList *LB, SqList *&LC)
{
	int i = 0, j = 0, k = 0; // i、j 分别为 LA、LB 的下标，k 为 LC 中元素个数
	
	LC = (SqList *)malloc(sizeof(SqList)); // 建立有序顺序表 LC
	
	while (i < LA->length && j < LB->length)
	{
		if (LA->data[i] < LB->data[j])
		{
			LC->data[k] = LA->data[i];
			i++;
			k++;
		}
		else // LA->data[i] > LB->data[j]
		{
			LC->data[k] = LB->data[j];
			j++;
			k++;
		}
	}
	
	while (i < LA->length) // LA 尚未扫描完，将其余元素插入 LC 中
	{
		LC->data[k] = LA->data[i];
		i++;
		k++;
	}
	
	while (j < LB->length) // LB 尚未扫描完，将其余元素插入 LC 中
	{
		LC->data[k] = LB->data[j];
		j++;
		k++;
	}
	
	LC->length = k;
}
//单链表二路归并
//void UnionList(LinkNode *LA, LinkNode *LB, LinkNode *&LC)
//{
//	LinkNode *pa=LA->next, *pb=LB->next, *r, *s;
//	LC=(LinkNode *)malloc(sizeof(LinkNode)); // 创建 LC 的头结点
//	r=LC;                                    // r 始终指向 LC 的尾结点
//	
//	while (pa!=NULL && pb!=NULL)
//	{
//		if (pa->data < pb->data)
//		{
//			s=(LinkNode *)malloc(sizeof(LinkNode)); // 复制结点
//			s->data=pa->data;
//			r->next=s;
//			r=s; // 采用尾插法将 s 插入到 LC 中
//			pa=pa->next;
//		}
//		else
//		{
//			s=(LinkNode *)malloc(sizeof(LinkNode)); // 复制结点
//			s->data=pb->data;
//			r->next=s;
//			r=s; // 采用尾插法将 s 插入到 LC 中
//			pb=pb->next;
//		}
//	}
//	
//	while (pa!=NULL)
//	{
//		s=(LinkNode *)malloc(sizeof(LinkNode)); // 复制结点
//		s->data=pa->data;
//		r->next=s;
//		r=s; // 采用尾插法将 s 插入到 LC 中
//		pa=pa->next;
//	}
//	
//	while (pb!=NULL)
//	{
//		s=(LinkNode *)malloc(sizeof(LinkNode)); // 复制结点
//		s->data=pb->data;
//		r->next=s;
//		r=s; // 采用尾插法将 s 插入到 LC 中
//		pb=pb->next;
//	}
//	
//	r->next=NULL; // 尾结点的 next 域置空
//}




// 找出两个等长的升序序列合并后的序列的中位数
//int M_Search(int A[], int B[], int n) {
//	int i, j, k;
//	i = j = k = 0;
//	while (i < n && j < n) {
//		k++;
//		if (A[i] < B[j]) {
//			if (k == n) {
//				return A[i];
//			}
//			i++;
//		} else {  // A[i] >= B[j]
//			if (k == n) {
//				return B[j];
//			}
//			j++;
//		}
//	}
//	// 如果循环结束没找到（理论上不会发生，因为 n 等于数组长度）
//	return -1; 
//}
//
//int main() {
//	int A[] = {1, 3, 5, 7};
//	int B[] = {2, 4, 5, 8};
//	int n = 4; // 数组长度
//	int result = M_Search(A, B, n);
//	printf("第 %d 个同时出现的元素是：%d\n", n, result);
//	return 0;
//}
