#include "linkList.h"

int main()
{
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	int n;
	scanf("%d",&n);
	printf("n=%d\n", n);
	CreateList_L(L,n);
	LinkList pointer = L->next;
	
	while(pointer)
	{
		printf("%d\n", pointer->data);
		pointer = pointer->next;
	}
	
	printf("length of L: %d\n", lengthList_L(L));

	BubbleSortList_L(L);

	pointer = L->next;
	while(pointer)
	{
		printf("%d\n", pointer->data);
		pointer = pointer->next;
	}
	ReverseList_L(L);
	pointer = L->next;
	while(pointer)
	{
		printf("%d\n", pointer->data);
		pointer = pointer->next;
	}
	return 0;
}
