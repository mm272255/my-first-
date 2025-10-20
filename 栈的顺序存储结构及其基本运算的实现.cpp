#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;        // 栈顶指针
} SqStack;
//初始化
void InitStack(SqStack *&s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}
//销毁
void DestroyStack(SqStack *&s)
{
	free(s);
}
//判断是否为空
bool StackEmpty(SqStack*s){
	return (s->top==-1);
}
//进栈
bool Push(SqStack *&s, ElemType e)
{
	if (s->top == MaxSize - 1)  // 栈满的情况，即栈上溢出
		return false;
	s->top++;                   // 栈顶指针增 1
	s->data[s->top] = e;        // 元素 e 放在栈顶指针处
	return true;
}
//出栈
bool Pop(SqStack *&s, ElemType &e)
{
	if (s->top == -1)  // 栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];  // 取栈顶指针元素的元素
	s->top--;             // 栈顶指针减 1
	return true;
}
//取栈顶元素
bool GetTop(SqStack *s, ElemType &e)
{
	if (s->top == -1)  // 栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];  // 取栈顶指针元素的元素
	return true;
}
//判断是否对称
bool symmetry(ElemType str[])
{
	int i;
	ElemType e;
	SqStack *st;
	
	InitStack(st);                // 初始化栈
	
	for (i=0; str[i]!='\0'; i++)  // 将串所有元素进栈
		Push(st, str[i]);         // 元素进栈
	
	for (i=0; str[i]!='\0'; i++)
	{
		Pop(st, e);               // 退栈元素 e
		if (str[i]!=e)            // 若 e 与当前串元素不同则不是对称串
		{
			DestroyStack(st);     // 销毁栈
			return false;
		}
	}
	
	DestroyStack(st);             // 销毁栈
	return true;
}
//将十进制转换为二进制

void trans(int n)
{
	int e;
	SqStack *st;
	InitStack(st);
	
	while (n > 0)
	{
		Push(st, n % 2);
		n = n / 2;
	}
	
	while (!StackEmpty(st))  // 输出对应的二进制数
	{
		Pop(st, e);
		printf("%d", e);
	}
	printf("\n");
	DestroyStack(st);
}
//判断是否是合法出栈序列
bool Validseq(int a[], int n)
{
	int i, e, k = 0;  // k 扫描 a 的元素
	bool flag;
	SqStack *st;
	
	InitStack(st);
	
	for (i = 1; i <= n; i++)  // 处理输入序列 1、2、…、n
	{
		Push(st, i);  // i 进栈
		
		while (!StackEmpty(st))  // 栈不空循环
		{
			GetTop(st, e);  // 取栈顶元素 e
			
			if (a[k] == e)  // 匹配的情况
			{
				Pop(st, e);
				k++;
			}
			else
				break;  // 不匹配时退出 while 循环
		}
	}
	
	flag = StackEmpty(st);
	DestroyStack(st);
	return flag;
}
