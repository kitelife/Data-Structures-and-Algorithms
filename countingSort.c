// counting sort
// 2012/4/13
// youngsterxyf
//
#include <stdlib.h>
#include <stdio.h>

void counting_sort(int *array, int size)
{
	int i, min, max;

	min = max = array[0];

	for(i = 1; i < size; i++)
	{
		if(array[i] < min)
			min = array[i];
		else if(array[i] > max)
			max = array[i];
	}

	int range = max - min + 1;
	int *count = (int *)malloc(range * sizeof(int));

	for(i = 0; i < range; i++)
		count[i] = 0;
	for(i = 0; i < size; i++)
		count[array[i] - min]++;

	int j, z = 0;
	for(i = min; i <= max; i++)
		for(j = 0; j < count[i - min]; j++)
			array[z++] = i;

	free(count);
}

int main()
{
	int intArray[10]={100,1,55,23,18,100,73,77,32,23};
	counting_sort(intArray, 10);
	int index;
	for(index = 0; index < 10; index ++)
		printf("%d ", intArray[index]);
	printf("\n");

	return 0;
}
