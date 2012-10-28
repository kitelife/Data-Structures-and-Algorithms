#include <stdio.h>
#include <stdlib.h>

int max2(int, int);

int main()
{
	int test[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
	int maxsofar = 0, maxendinghere = 0;
	int i;
	for(i=0; i<10; i++){
		maxendinghere = max2(maxendinghere+test[i], 0);
		maxsofar = max2(maxsofar, maxendinghere);
	}
	printf("%d\n", maxsofar);

	return 0;
}

int max2(int i, int j)
{
	return ((i-j)>0) ? i : j;
}