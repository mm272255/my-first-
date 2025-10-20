#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;        // 栈顶指针
} SqStack;

typedef struct
{
	ElemType data[MaxSize];
	int top;        // 栈顶指针
} SqStack1;
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
void InitStack1(SqStack1 *&s)
{
	s = (SqStack1 *)malloc(sizeof(SqStack1));
	s->top = -1;
}
//销毁
void DestroyStack1(SqStack1 *&s)
{
	free(s);
}
//判断是否为空
bool Stack1Empty(SqStack1*s){
	return (s->top==-1);
}
//进栈
bool Push1(SqStack1 *&s, ElemType e)
{
	if (s->top == MaxSize - 1)  // 栈满的情况，即栈上溢出
		return false;
	s->top++;                   // 栈顶指针增 1
	s->data[s->top] = e;        // 元素 e 放在栈顶指针处
	return true;
}
//出栈
bool Pop1(SqStack1 *&s, double &e)
{
	if (s->top == -1)  // 栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];  // 取栈顶指针元素的元素
	s->top--;             // 栈顶指针减 1
	return true;
}
//取栈顶元素
bool GetTop1(SqStack1 *s, double &e)
{
	if (s->top == -1)  // 栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];  // 取栈顶指针元素的元素
	return true;
}
//简单表达式求值
void trans(char*exp,char postexp[]){
	char e;
	SqStack*Optr;
	InitStack(Optr);
	int i=0;
	while(*exp!='\0'){
		switch(*exp){
		case'(':
			Push(Optr,'(');
			exp++;
			break;
		case')':
			Pop(Optr,e);
			while(e!='('){
				postexp[i++]=e;
				Pop(Optr,e);
			}
			exp++;
			break;
		case'+':
		case'-':
			while(!StackEmpty(Optr)){
				GetTop(Optr,e);
				if(e!='('){
					postexp[i++]=e;
					Pop(Optr,e);
				}else{
					break;
				}
			}
			Push(Optr,*exp);
			exp++;
			break;
		case'*':
		case'/':
			while(!StackEmpty(Optr)){
				GetTop(Optr,e);
				if(e=='*'||e=='/'){
					postexp[i++]=e;
					Pop(Optr,e);
				}else{
					break;
				}
			}
			Push(Optr,*exp);
			exp++;
			break;
		default:
			while(*exp>='0'&&*exp<='9'){
				postexp[i++]=*exp;
				exp++;
			}
			postexp[i++]='#';
		}
	}
	while(!StackEmpty(Optr)){
		Pop(Optr,e);
		postexp[i++]=e;
	}
	postexp[i]='\0';
	DestroyStack(Optr);	
}
//计算后缀表达上的值
double compvalue(char *postexp){
	double d,a,b,c,e;
	SqStack1*Opnd;
	InitStack1(Opnd);
	while(*postexp!='\0'){
		switch(*postexp){
		case'+':
			Pop1(Opnd,a);
			Pop1(Opnd,b);
			c=b+a;
			Push1(Opnd,c);
			break;
		case'-':
			Pop1(Opnd,a);
			Pop1(Opnd,b);
			c=b-a;
			Push1(Opnd,c);
			break;
		case'*':
			Pop1(Opnd,a);
			Pop1(Opnd,b);
			c=b*a;
			Push1(Opnd,c);
			break;
		case'/':
			Pop1(Opnd,a);
			Pop1(Opnd,b);
			if(a!=0){
				c=b/a;
				Push1(Opnd,c);
				break;
			}else{
				cout<<"除零错误!"<<endl;
				exit(0);
			}
			break;
		default:
			d=0;
			while(*postexp>='0'&&*postexp<='9'){
				d=10*d+*postexp-'0';
				postexp++;//向后移动指针
			}
			Push1(Opnd,d);
			break;
		}
		postexp++;
	}
	GetTop1(Opnd,e);
	DestroyStack1(Opnd);
	return e;
}
int main(){
	char exp[]="(56-20)/(4+2)";
	char postexp[MaxSize];
	trans(exp,postexp);
	cout<<"中缀表达式："<<exp<<endl;
	cout<<"后缀表达式："<<postexp<<endl;
	cout<<"表达式的值："<<compvalue(postexp);
}
