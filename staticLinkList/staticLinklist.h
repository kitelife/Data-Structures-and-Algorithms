#include<stdio.h>
#include<stdlib.h>
#define	MAXSIZE	1000
typedef int ElemType;

typedef	struct {
	ElemType	data;
	int	cur;
}component, *SLinkList;

int LocateElem_L(SLinkList, ElemType);

void InitSpace_SL(SLinkList);

int Malloc_SL(SLinkList);

void Free_SL(SLinkList, int);
