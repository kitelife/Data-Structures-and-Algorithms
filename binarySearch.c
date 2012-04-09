#include <stdio.h>
#include <assert.h>

#define	MAXN	100

typedef	int	DataType;

int binarysearch(DataType *x, DataType t, int n)
{
	int l, u, m;
	l = 0;
	u = n - 1;
	while(l <= u){
		m = (l + u) / 2;
		if(x[m] < t)
			l = m + 1;
		else if(x[m] == t)
			return m;
		else
			u = m - 1;
	}
	
	return -1;
}

int sorted(DataType *, int);

int main()
{
	int n, i;
	DataType t, x[MAXN];
	while(scanf("%d %d", &n, &t) != EOF){
		for(i = 0; i < n; i++)
			x[i] = 10 * i;

		assert(sorted(x, n));
		printf(" %d\n", binarysearch(x, t, n));
	}

	return 0;
}

int sorted(DataType *x, int n)
{
	int i;
	for(i = 0; i < n - 1; i++)
		if(x[i] > x[i+1])
			return 0;

	return 1;
}
