#include<stdlib.h>
#include<stdio.h>

#define OK	0
#define ERROR	1

typedef int ElemType;
typedef int Status;

typedef struct LNode{
	ElemType		data;
	struct LNode	*next;
}LNode, *LinkList;

Status GetElem_L(LinkList L, int i, ElemType *e)
{
	// L为带头结点的单链表的头指针。
	// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
	LNode *p = L.next;
	int j = 1;
	while(p && j < i){
		p = p->next;
		++j;
	}
	if(!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

Status ListInsert_L(LinkList L, int i, ElemType e)
{
	// 在带头结点的单链表L中第i个位置之前插入元素e
	LinkList p = L;
	int j = 0;
	while(p && j < i-1) // find i-1 th node
	{
		p = p->next;
		++j;
	}

	if(!p || j > i-1)
		return ERROR;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return OK;
}

Status ListDelete_L(LinkList L, int i, ElemType *e)
{
	// 在带头结点的单链表L中，删除第i个元素，并由e返回其值
	LinkList p = L;
	int j = 0;
	while(p->next && j < i-1){	//寻找第i个结点，并令p指向其前趋
		p = p->next;
		++j;
	}

	if(!(p->next) || j > i-1)
		return ERROR;
	LinkList q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);

	return OK;
}

void CreateList_L(LinkList L, int n)
{
	// 逆位序输入n个元素的值，建立带表头结点的单链线性表L
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;

	int i;
	for(i = n; i > 0; --i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		scanf(&(p->data));
		p->next = L->next;
		L->next = p;
	}
}

void MergeList_L(LinkList La, LinkList Lb, LinkList Lc)
{
	// 已知单链线性表La和Lb的元素按值非递减排列
	// 归并La和Lb得到新的单链线性表Lc,Lc的元素也按值非递减排列
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	LinkList pc = Lc = La;	// use the head of La as the head of Lc

	while(pa && pb){
		if(pa->data <= pb->data){
			pc->next = pa; // need???
			pc = pa;
			pa = pa->next;
		}
		else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}
