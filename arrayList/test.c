#include<stdio.h>
#include "arrayList.h"

int main()
{
	int i;
	/*
	SqList first, second;
	InitList_Sq(&first);
	InitList_Sq(&second);
	for(i = 1; i <= first.listsize; i++){
		ListInsert_Sq(&first, i, i-1);
		ListInsert_Sq(&second, i, i+50);
	}
	
	for(i = 0; i < first.length; i++){
		printf("first.elem[%d]=%d\n", i, first.elem[i]);
		printf("second.elem[%d]=%d\n", i, second.elem[i]);
	}
	SqList third;
	MergeList_Sq(first, second, &third);
	for(i = 0; i < third.length; i++)
		printf("third.elem[%d]=%d\n", i, third.elem[i]);
	printf("LocateElem_Sq:%d, %d\n", 50, LocateElem_Sq(third,50,&compare));
	printf("LocateElem_Sq:%d, %d\n", 52, LocateElem_Sq(third,52,&compare));
	printf("LocateElem_Sq:%d, %d\n", 100, LocateElem_Sq(third, 1000, &compare));
	
	ElemType elemDeleted;
	ListDelete_Sq(&third, 100, &elemDeleted);
	printf("elemDeleted In third---> %d\n", elemDeleted);
	for(i = 0; i < third.length; i++)
		printf("third.elem[%d]: %d\n", i, third.elem[i]);
	*/
	SqList four;
	InitList_Sq(&four);
	for(i = 1; i <= four.listsize; i++){
		ListInsert_Sq(&four, i, four.listsize - i);
		printf("four.elem[%d]: %d; ", i-1, four.elem[i-1]);
	}
	printf("\n");
	QSortList_Sq(&four);
	for(i = 0; i < four.length; i++)
		printf("four.elem[%d]: %d\n", i, four.elem[i]);
	
	return 0;
}
