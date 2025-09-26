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
void delnodel(SqList* &L,int x){
	int k=0;
	for(int i=0;i<L->length;++i){
		if(L->data[i]!=x){
			L->data[k]=L->data[i];
			k++;
		}
	}
	L->length=k;
}
void DispList(SqList*L){
	for(int i=0;i<L->length;++i){
		cout<<L->data[i]<<" ";
	}
	cout<<endl;
}
int main(){
	SqList *L;
	int deleteVal, n;  // deleteVal：要删除的值；n：手动录入的元素个数
	
	// 1. 初始化顺序表
	IniList(L);
	std::cout << "请输入顺序表的元素个数（不超过" << Maxsize << "）：";
	std::cin >> n;
	
	// 2. 录入测试数据
	if(n > 0 && n <= Maxsize){
		std::cout << "请输入" << n << "个整数（空格分隔）：";
		for(int i=0; i<n; ++i){
			std::cin >> L->data[i];
		}
		L->length = n;  // 更新顺序表实际长度
	} else {
		std::cout << "元素个数输入错误！" << std::endl;
		return 1;
	}
	
	// 3. 输出删除前的顺序表
	std::cout << "\n删除前的顺序表：";
	DispList(L);
	
	// 4. 输入要删除的值，并调用删除函数
	std::cout << "请输入要删除的数值：";
	std::cin >> deleteVal;
	delnodel(L, deleteVal);
	
	// 5. 输出删除后的顺序表
	std::cout << "删除后的顺序表：";
	DispList(L);
	
	// 6. 释放动态分配的内存（避免内存泄漏）
	free(L);
	L = NULL;
	
	return 0;
}
