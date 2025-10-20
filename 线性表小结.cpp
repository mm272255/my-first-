//荷兰国旗问题-顺序表
//void move1(SqList *&L)
//{
//	int i = -1, j = 0, k = L->length;
//	while (j < k)
//	{
//		if (L->data[j] == 0)
//		{
//			i++;
//			swap(L->data[i[j L->data[j]);
//			j++;
//		}
//		else if (L->data[j] == 2)
//		{
//			k--;
//			swap(L->data[k[j L->data[j]);
//		}
//		else
//			j++;    // L->data[j]==1 的情况
//	}
//}
//荷兰国旗问题-单链表
//void move2(LinkList *&L)
//{
//	LinkList *L1, *L2, *r, *r1, *r2, *p;
//	L1 = NULL;
//	L2 = NULL;
//	p = L->next;
//	r = L;
//	
//	while (p != NULL)
//	{
//		if (p->data == 0)
//		{
//			r->next = p;
//			r = p;
//		}
//		else if (p->data == 1)
//		{
//			if (L1 == NULL)
//			{
//				L1 = p;
//				r1 = p;
//			}
//			else
//			{
//				r1->next = p;
//				r1 = p;
//			}
//		}
//		else    // p->data == 2
//		{
//			if (L2 == NULL)
//			{
//				L2 = p;
//				r2 = p;
//			}
//			else
//			{
//				r2->next = p;
//				r2 = p;
//			}
//		}
//		p = p->next;
//	}
//	
//	r->next = r1->next = r2->next = NULL;
//	r->next = L1;          // L 的尾结点和 L1 的首结点链接起来
//	r1->next = L2;         // L1 的尾结点和 L2 的首结点链接起来
//}

//有序表用顺序表存储，删除重复元素
//void deldupnode1(SqList *&L)
//{
//	int k=1,i;    //k记录保留的元素个数
//	for (i=1; i<L->length; i++)
//		if (L->data[i] != L->data[i-1])
//		{
//			L->data[k] = L->data[i];
//			k++;    //保留的元素增1
//		}
//	L->length = k; //顺序表L的长度等于k
//}

//用一个单链表存储两个用单链表存储的递增有序表的公共元素
//void InterSect(LinkList *ha, LinkList *hb, LinkList *&hc)
//{
//	LinkList *pa=ha->next, *pb=hb->next, *s, *r;
//	hc=(LinkNode *)malloc(sizeof(LinkNode));
//	r=hc;            // r 指向尾结点
//	while (pa!=NULL && pb!=NULL)
//	{
//		if (pa->data < pb->data) pa=pa->next;
//		if (pa->data > pb->data) pb=pb->next;
//		if (pa->data == pb->data)      // 相同元素
//		{
//			s=(LinkNode *)malloc(sizeof(LinkNode));
//			// 复制结点
//			s->data=pa->data;
//			r->next=s;  r=s;
//			pa=pa->next; pb=pb->next;
//		}
//	}
//	r->next=NULL;
//}

