#include "staticLinklist.h"

void difference(SLinkList, int *);

int main()
{
	SLinkList sp = (SLinkList)malloc(sizeof(component)*MAXSIZE);
	int hS = 0;
	difference(sp, &hS);
	int first = sp[hS].cur;
	while(first)
	{
		printf("%d: %d->%d\n", first, sp[first].data, sp[first].cur);
		first = sp[first].cur;
	}

	return 0;
}

void difference(SLinkList space, int *S)
{
	// 依次输入集合A和B的元素，在一维数组space中建立表示集合(A-B)U(B-A)
	// 的静态链表，S为其头指针。假设备用空间足够大，space[0].cur为其头指针
	InitSpace_SL(space);
	*S = Malloc_SL(space);
	int r = *S;
	int m, n, j, i;
	scanf("%d",&m);
	scanf("%d", &n);
	for(j = 1; j <= m; ++j)
	{
		i = Malloc_SL(space);
		scanf("%d",&(space[i].data));
		space[r].cur=i;
		r = i;
	}// for
	printf("A input end!\n");
	space[r].cur = 0;
	int b, p, k;
	for(j = 1; j <= n; ++j)	// 依次输入B的元素，若不在当前表中，则插入，否则删除
	{
		scanf("%d",&b);
		p = *S;
		k = space[*S].cur;
		while(k != space[r].cur && space[k].data != b){
			p = k;
			k = space[k].cur;
		}// while
		// 当前表中不存在该元素，插入在r所指结点之后，且r的位置不变
		if(k == space[r].cur){
			i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		} // if
		//该元素已在表中，删除之
		else{
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if(r == k)
				r = p;
		}// else
	}// for
}// difference
