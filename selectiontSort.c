#include <stdio.h>

void selectionSort(int *data, int count)
{
	int i, j, min, temp;
	for(i = 0; i < count-1; i++)
	{
		min = i;
		for(j = i + 1; j < count; j++)
		{
			if(data[j] < data[min])
				min = j;
		}
		temp = data[i];
		data[i] = data[min];
		data[min] = temp;
	}
}

int main()
{
	int intArray[6] = {10, 4, 15, 27, 1, 3};
	selectionSort(intArray, 6);
	int index;
	for(index = 0; index < 6; index++)
		printf("%d	", intArray[index]);
	printf("\n");

	return 0;
}
