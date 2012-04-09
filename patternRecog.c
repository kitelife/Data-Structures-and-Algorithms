// Programming Pearls: Column 8
//
#include <stdio.h>
#include <stdlib.h>

float maxsum3(int [], int, int);
int max2(int, int);
int max3(int, int, int);

int test[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

int main()
{
	int maxsum = maxsum3(test,0,9);
	printf("%d\n", maxsum);

	return 0;
}

float maxsum3(int *x, int l, int u)
{
	if(l > u)	// zero elements
		return 0;
	if(l == u)	// one element
		return max2(0, x[1]);
	int m = (l + u) / 2;
	// find max crossing to left
	int lmax=0, sum = 0;
	int i;
	for(i = m; i >= 1; i--){
		sum += x[i];
		lmax = max2(lmax, sum);
	}
	// find max crossing to right
	sum = 0;
	int rmax = 0;
	for(i=m+1; i <=u; i++)
	{
		sum += x[i];
		rmax = max2(rmax, sum);
	}
	return max3(lmax+rmax, maxsum3(x, l, m), maxsum3(x, m+1, u));
}

int max2(int i, int j)
{
	int temp = ((i-j)>0) ? i : j;
	return temp;
}

int max3(int i, int j, int k)
{
	int temp = ((i-j)>0) ? i : j;
	return ((temp-k)>0) ? temp : k;
}
