/*
 * 连通问题的快速查找算法
 *
 * 程序从标准输入读取小于N的非负整数对序列，并且输出还未连通的输入对。
 * 程序中使用数组id，每个元素表示一个对象，且具有以下性质，当且仅当
 * p和q是连通的，id[p]和id[q]相等。
 *
 * 为简化起见，定义N为编译时的常数。
 *
 * 为了实现查找操作，只需测试指示数组中的元素是否相等，因此称之为
 * 快速查找。而合并操作对于每对输入需要扫描整个数组。
 */

#include <stdio.h>
#define N 10000

int main()
{
	int biggest = 0;
	int i, p, q, t, id[N];
	for(i = 0; i < N; i++)
		id[i] = i;
	while(scanf("%d %d\n", &p, &q) == 2){
		if((p > q)&&(p > biggest))
			biggest = p;
		else if((p <= q)&&(q > biggest))
			biggest = q;

		if (id[p]==id[q])
			continue;
		for (t = id[p], i = 0; i < N; i++)
			if (id[i] == t)
				id[i] = id[q];
		printf(" %d %d\n", p, q);
	}
	printf("Biggest: %d\n", biggest);
	while(biggest >= 0){
		printf("%d ", id[biggest]);
		biggest--;
	}
	printf("\n");

	return 0;
}
