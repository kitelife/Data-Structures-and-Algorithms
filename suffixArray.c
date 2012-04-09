// 后缀数组
// Programming Pearls: Column 15

#include <stdio.h>
#include <stdlib.h>

#define	MAXN	500

char c[MAXN], *a[MAXN];

int main()
{
	char ch;
	int n = 0;
	while((ch  = getchar()) != EOF)
	{
		a[n] = &c[n];
		c[n++] = ch;
	}
	c[n] = 0;
	qsort(a, n, sizeof(char *), pstrcmp);	
	for(n = 0; a[n]; n++)
		printf("%s\n", a[n]);

	return 0;
}
