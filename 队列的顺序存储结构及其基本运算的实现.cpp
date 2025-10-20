#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int front,rear;
}SqQuene;
//void InitQuene(SqQuene*&q){
//	q=(SqQuene*)malloc(sizeof(SqQuene));
//	q->front=q->rear=-1;
//}
//void DestroyQuene(SqQuene*&q){
//	free(q);
//}
//bool QueneEmpty(SqQuene*q){
//	return (q->front==q->rear);
//}
//bool enQuene(SqQuene*&q,ElemType e){
//	if(q->rear==MaxSize-1)
//		return false;
//	q->rear++;
//	q->data[q->rear]=e;
//	return true;
//}
//bool deQuene(SqQuene*&q,ElemType &e){
//	if(q->front==q->rear)
//		return false;
//	q->front++;
//	e=q->data[q->front];
//	return true;
//}
//环形队列
//void InitQuene(SqQuene*&q){
//	q=(SqQuene*)malloc(sizeof(SqQuene));
//	q->front=q->rear=0;
//}
//void DestroyQuene(SqQuene*&q){
//	free(q);
//}
//bool QueneEmpty(SqQuene*q){
//	return (q->front==q->rear);
//}
//bool enQuene(SqQuene*&q,ElemType e){
//	if((q->rear+1)%MaxSize==q->front)
//		return false;
//	q->rear=(q->rear+1)%MaxSize;
//	q->data[q->rear]=e;
//	return true;
//}
//bool deQuene(SqQuene*&q,ElemType &e){
//	if(q->front==q->rear)
//		return false;
//	q->front=(q->front+1)%MaxSize;
//	e=q->data[q->front];
//	return true;
//}
//int Count(SqQuene*q){
//	return (q->rear-q->front+MaxSize)%MaxSize;
//}
//已知队头指针和队列中元素个数，实现其基本功能
typedef struct{
   ElemType data[MaxSize];
	int front;
	int count;
}QuType;
void InitQuene(QuType*&qu){
	qu=(QuType*)malloc(sizeof(QuType));
	qu->front=0;
	qu->count=0;
}
bool EnQuene(QuType*&qu,ElemType x){
	int rear;
	if(qu->count==MaxSize)
		return false;
	else{
		rear=(qu->front+qu->count)%MaxSize;
		rear=(rear+1)%MaxSize;
		qu->data[rear]=x;
		qu->count++;
		return true;
	}
}
bool DeQuene(QuType*&qu,ElemType &x){
	if(qu->count==0)
		return false;
	qu->front=(qu->front+1)%MaxSize;
	x=qu->data[qu->front];
	qu->count--;
	return true;
}
bool QueneEmpty(QuType*qu){
	return (qu->count==0);
}

