// 约瑟夫问题
//
// 假设有N个人决定选出一个领导人，方法如下：
// 所有人排成一个圆圈，按顺序数数，每隔第M的人出局，
// 此时，他两边的人靠拢重新形成圆圈。问题是找出
// 哪一个人将会是最后剩下的那个人。
//
// 2012.3.25
//
#include<stdio.h>
#include<stdlib.h>

typedef struct node* link;
struct node{
	int item;
	link next;
};

int main(int argc, char *argv[])
{
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	link t = malloc(sizeof *t), x = t;
	t->item = 1;
	t->next = t;
	for(i = 2; i <= N; i++)
	{
		x = (x->next = malloc(sizeof *x));
		x->item = i;
		x->next = t;
	}
	while(x != x->next){
		for(i = 1; i < M; i++)
			x = x->next;
		x->next = x->next->next;
		N--;
	}

	printf("%d\n", x->item);

	return 0;
}
