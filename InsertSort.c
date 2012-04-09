#include <stdio.h>

int test[5] = {10, 9, 4, 50, 3};

int main()
{
	int i, j, temp;
	for(i = 1; i < 5; i++)
		for(j = i; j>0 && test[j-1]>test[j]; j--){
			temp = test[j-1];
			test[j-1] = test[j];
			test[j] = temp;
		}
	for(i = 0; i < 5; i++)
		printf("%d\n", test[i]);
	return 0;
}
