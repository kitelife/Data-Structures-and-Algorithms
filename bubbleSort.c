#include <stdio.h>

void bubbleSort(int arr[], int count)
{
	int i=count, j;
	int temp;

	while(i>0)
	{
		for(j=0; j<i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		i--;
	}
}

int main()
{
	int arr[] = {5, 4, 1, 3, 6};
	bubbleSort(arr, 5);
	int i;
	for(i=0; i<5; i++)
		printf("%4d", arr[i]);
}
