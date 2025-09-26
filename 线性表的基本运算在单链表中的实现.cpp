#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode*next;
}LinkNode;
//初始化线性表
void InitList(LinkNode*&L){
	L=(LinkNode*)malloc(sizeof(LinkNode));
	L->next=NULL;
}
//销毁线性表
void DestroyList(LinkNode*&L){
	LinkNode*pre=L,*p=L->next;
	while(p!=NULL){
		free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);
}
//判断线性表是否为空表
bool ListEmpty(LinkNode*L){
	return (L->next==NULL);
}
//求线性表的长度
int ListLength(LinkNode*L){
	LinkNode*p=L;
	int n=0;
	while(p->next!=NULL){
		n++;
		p=p->next;
	}
	return n;
}
//输出线性表
void DispList(LinkNode*L){
	LinkNode*p=L->next;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;	
	}
	cout<<endl;
}
//按序号求线性表中元素
bool GetElem(LinkNode*L,int i,ElemType &e){
	int j=0;
	LinkNode*p=L;
	if(i<=0) return false;
	while(j<i&&p!=NULL){
		j++;
		p=p->next;
	}
	if(p==NULL){
		return false;
	}else{
		e=p->data;
		return true;
	}
}
//按元素值查找,返回逻辑符号
int LocateElem(LinkNode*L,ElemType e){
	int i=1;
	LinkNode*p=L->next;
	while(p!=NULL&&p->data!=e){
		p=p->next;
		i++;
	}
	if(p==NULL){
		return false;
	}else{
		return i;
	}
}
//插入数据元素
bool ListInsert(LinkNode*&L,int i,ElemType e){
	int j=0;
	LinkNode*p=L,*s;
	if(i<=0) return false;
	while(j<i-1&&p!=NULL){
		j++;
		p=p->next;
	}
	if(p==NULL) return false;
	else{
		s=(LinkNode*)malloc(sizeof(LinkNode));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
}
//删除数据元素
bool ListDelete(LinkNode*&L,int i,ElemType &e){
	int j=0;
	LinkNode*p=L,*q;
	if(i<=0) return false;
	while(j<i-1&&p!=NULL){
		j++;
		p=p->next;
	}
	if(p==NULL) return false;
	else{
		q=p->next;
		if(q==NULL){
			return false;
		}
		e=q->data;
		p->next=q->next;
		free(q);
		return true;
	}
}
void CreateListR(LinkNode*&L,ElemType a[],int n){
	LinkNode*s,*r;
	L=(LinkNode*)malloc(sizeof(LinkNode));
	r=L;
	for(int i=0;i<n;++i){
		s=(LinkNode*)malloc(sizeof(LinkNode));
		s->data=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
}
int main() {
	LinkNode* L;          // 单链表头指针
	ElemType e;           // 存储获取/删除的元素值
	bool flag;            // 接收函数成功/失败状态
	int pos;              // 存储按值查找的位置
	// 测试用数组（后续用尾插法创建链表）
	ElemType test_arr[] = {11, 22, 33, 44, 55, 66};
	int arr_len = sizeof(test_arr) / sizeof(test_arr[0]);  // 数组长度：6
	
	// 1. 测试尾插法创建链表（CreateListR）
	cout << "===== 1. 测试尾插法创建链表 =====" << endl;
	CreateListR(L, test_arr, arr_len);
	cout << "尾插创建后，链表元素：";
	DispList(L);  // 预期输出：11 22 33 44 55 66
	cout << "链表长度：" << ListLength(L) << endl;  // 预期输出：6
	cout << "链表是否为空？" << (ListEmpty(L) ? "是" : "否") << endl << endl;  // 预期输出：否
	
	// 2. 测试按序号查找元素（GetElem）
	cout << "===== 2. 测试按序号查找 =====" << endl;
	// 测试1：合法序号（3、6）
	flag = GetElem(L, 3, e);
	cout << "查找第3位元素：" << (flag ? ("成功，值为：" + to_string(e)) : "失败（序号非法/超出长度）") << endl;  // 预期：33
	flag = GetElem(L, 6, e);
	cout << "查找第6位元素：" << (flag ? ("成功，值为：" + to_string(e)) : "失败（序号非法/超出长度）") << endl;  // 预期：66
	// 测试2：非法序号（0、8）
	flag = GetElem(L, 0, e);
	cout << "查找第0位元素：" << (flag ? ("成功，值为：" + to_string(e)) : "失败（序号非法/超出长度）") << endl;  // 预期：失败
	flag = GetElem(L, 8, e);
	cout << "查找第8位元素：" << (flag ? ("成功，值为：" + to_string(e)) : "失败（序号非法/超出长度）") << endl << endl;  // 预期：失败
	
	// 3. 测试按元素值查找（LocateElem）
	cout << "===== 3. 测试按值查找 =====" << endl;
	// 测试1：查找存在的元素（44、11）
	pos = LocateElem(L, 44);
	cout << "查找元素44：" << (pos ? ("成功，位于第" + to_string(pos) + "位") : "失败（元素不存在）") << endl;  // 预期：4
	pos = LocateElem(L, 11);
	cout << "查找元素11：" << (pos ? ("成功，位于第" + to_string(pos) + "位") : "失败（元素不存在）") << endl;  // 预期：1
	// 测试2：查找不存在的元素（77、25）
	pos = LocateElem(L, 77);
	cout << "查找元素77：" << (pos ? ("成功，位于第" + to_string(pos) + "位") : "失败（元素不存在）") << endl;  // 预期：失败
	pos = LocateElem(L, 25);
	cout << "查找元素25：" << (pos ? ("成功，位于第" + to_string(pos) + "位") : "失败（元素不存在）") << endl << endl;  // 预期：失败
	
	// 4. 测试插入元素（ListInsert）
	cout << "===== 4. 测试插入元素 =====" << endl;
	cout << "插入前链表：";
	DispList(L);  // 初始：11 22 33 44 55 66
	// 测试1：合法插入（头部1、中间4、尾部7）
	flag = ListInsert(L, 1, 5);  // 头部插5
	cout << "第1位插入5：" << (flag ? "成功" : "失败") << endl;
	flag = ListInsert(L, 4, 30);  // 第4位插30（插入后第4位是30）
	cout << "第4位插入30：" << (flag ? "成功" : "失败") << endl;
	flag = ListInsert(L, 8, 70);  // 尾部插70（插入前长度7，合法位1-8）
	cout << "第8位插入70：" << (flag ? "成功" : "失败") << endl;
	// 测试2：非法插入（0、10）
	flag = ListInsert(L, 0, 99);  // 第0位非法
	cout << "第0位插入99：" << (flag ? "成功" : "失败") << endl;
	flag = ListInsert(L, 10, 88);  // 超出当前长度（插入后长度8，非法位10）
	cout << "第10位插入88：" << (flag ? "成功" : "失败") << endl;
	// 插入后结果
	cout << "插入后链表：";
	DispList(L);  // 预期：5 11 22 30 33 44 55 66 70
	cout << "插入后长度：" << ListLength(L) << endl << endl;  // 预期：9
	
	// 5. 测试删除元素（ListDelete）
	cout << "===== 5. 测试删除元素 =====" << endl;
	cout << "删除前链表：";
	DispList(L);  // 插入后：5 11 22 30 33 44 55 66 70
	// 测试1：合法删除（头部1、中间5、尾部9）
	flag = ListDelete(L, 1, e);  // 删头部5
	cout << "删除第1位：" << (flag ? ("成功，被删值：" + to_string(e)) : "失败") << endl;  // 预期：5
	flag = ListDelete(L, 5, e);  // 删第5位（当前第5位是44）
	cout << "删除第5位：" << (flag ? ("成功，被删值：" + to_string(e)) : "失败") << endl;  // 预期：44
	flag = ListDelete(L, 8, e);  // 删尾部70（删除前长度8，合法位1-8）
	cout << "删除第8位：" << (flag ? ("成功，被删值：" + to_string(e)) : "失败") << endl;  // 预期：70
	// 测试2：非法删除（0、9）
	flag = ListDelete(L, 0, e);  // 第0位非法
	cout << "删除第0位：" << (flag ? ("成功，被删值：" + to_string(e)) : "失败") << endl;  // 预期：失败
	flag = ListDelete(L, 9, e);  // 超出当前长度（删除后长度6，非法位9）
	cout << "删除第9位：" << (flag ? ("成功，被删值：" + to_string(e)) : "失败") << endl;  // 预期：失败
	// 删除后结果
	cout << "删除后链表：";
	DispList(L);  // 预期：11 22 30 33 55 66
	cout << "删除后长度：" << ListLength(L) << endl << endl;  // 预期：6
	
	// 6. 测试销毁链表（DestroyList）
	cout << "===== 6. 测试销毁链表 =====" << endl;
	DestroyList(L);
	cout << "链表已销毁（后续不可访问链表内容）" << endl;
	
	return 0;
}
