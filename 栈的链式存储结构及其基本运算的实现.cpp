#include<iostream>
#include<stdlib.h>
using namespace std;
typedef char ElemType;
typedef struct linknode{
	ElemType data;
	struct linknode *next;
}LinkStNode;
//初始化
void InitStack(LinkStNode*&s){
	s=(LinkStNode*)malloc(sizeof(LinkStNode));
	s->next=NULL;
}
//销毁
void DestroyStack(LinkStNode*&s){
	LinkStNode*pre=s,*p=s->next;
	while(s->next!=NULL){
		free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);
}
//判断栈是否为空
bool StackEmpty(LinkStNode*s){
	return (s->next==NULL);
}
//进栈
bool Push(LinkStNode*&s,ElemType e){
	LinkStNode*p;
	p=(LinkStNode*)malloc(sizeof(LinkStNode));
	p->data=e;
	p->next=s->next;
	s->next=p;
	return true;
}
//出栈
bool Pop(LinkStNode*&s,ElemType &e){
	LinkStNode*p;
	if(s->next==NULL){
		return false;
	}
	p=s->next;
	e=p->data;
	s->next=p->next;
	free(p);
	return true;
}
//取栈顶元素
bool GetTop(LinkStNode*s,ElemType &e){
	if(s->next==NULL)
		return false;
	e=s->next->data;
	return true;
}
//设计一个算法判断输入表达式中括号是否配对
bool Match(char exp[],int n){
	int i=0;
	char e;
	bool match=true;
	LinkStNode*st;
	InitStack(st);
	while(i<n&&match){
		if(exp[i]=='('){
			Push(st,exp[i]);
		}else if(exp[i]==')'){
			if(GetTop(st,e)==true){
				if(e=='('){
					Pop(st,e);
				}else{
					match=false;
				}
			}else{
				match=false;
			}
		}
		i++;
	}
	if(!StackEmpty(st)){
		match=false;
	}
	DestroyStack(st);
	return match;
	
}
int main() {
	char exp[100];  // 存储输入的表达式，最大支持99个字符
	cout << "请输入待验证括号的表达式（仅支持()）：";
	cin.getline(exp, 100);  // 读取整行输入，可包含空格
	
	// 计算表达式实际长度（遍历到字符串结束符'\0'）
	int len = 0;
	while (exp[len] != '\0') {
		len++;
	}
	
	// 调用Match函数验证并输出结果
	if (Match(exp, len)) {
		cout << " 括号完全配对！" << endl;
	} else {
		cout << " 括号不配对！" << endl;
	}
	
	return 0;
}
