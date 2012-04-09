#include <stdio.h>

void QuickSort(int *data, int left, int right)
{
	int temp = data[left];
	int p = left;
	int i = left, j = right;

	while(i <= j)
	{
		while(data[j] >= temp && j >= p)
			j--;
		if(j >= p){
			data[p] = data[j];
			p = j;
		}

		while(data[i] <= temp && i <= p)
			i++;
		if(i <= p)
		{
			data[p] = data[i];
			p = i;
		}
	}
	data[p] = temp;
	if(p-left > 1)
		QuickSort(data, left, p-1);
	if(right-p > 1)
		QuickSort(data, p+1, right);
}

int main()
{
	int intArray[5] = {10, 1, 100, 78, -1};
	QuickSort(intArray, 0, 4);
	int index;
	for(index = 0; index < 5; index++)
		printf("%d	", intArray[index]);

	printf("\n");

	return 0;
}
