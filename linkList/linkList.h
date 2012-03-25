#include<stdio.h>
#include<stdlib.h>

#define OK	0
#define	ERROR	1

typedef int ElemType;
typedef int Status;

typedef struct LNode{
	ElemType	data;
	struct LNode	*next;
}LNode, *LinkList;

Status GetElem_L(LinkList, int, ElemType *);

Status ListInsert_L(LinkList, int, ElemType);

Status ListDelete_L(LinkList, int, ElemType *);

void CreateList_L(LinkList, int);

void MergeList_L(LinkList, LinkList, LinkList);

int lengthList_L(LinkList);

void BubbleSortList_L(LinkList);

void ReverseList_L(LinkList);
