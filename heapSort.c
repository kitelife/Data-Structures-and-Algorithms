#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEAP_SIZE 12

int parent(int);
int left(int);
int right(int);
void Max_Heapify(int *, int, int);
void Build_Max_Heap(int *);
void print(int *);
void HeapSort(int *, int);

//父结点
int parent(int i)
{
	return (int)floor(i / 2);
}

// left child
int left(int i)
{
	return 2 * i;
}

// right child
int right(int i)
{
	return (2 * i + 1);
}

//单一子结点最大堆树调整
void Max_Heapify(int* A, int i, int heap_size)
{
	int l = left(i);
	int r = right(i);
	int largest;
	int temp;
	if(l < heap_size && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if(r < heap_size && A[r] > A[largest])
		largest = r;
	if(largest != i){
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		Max_Heapify(A, largest, heap_size);
	}
}

//
void Build_Max_Heap(int* A)
{
	int i;
	for(i = (HEAP_SIZE-1)/2; i >= 0; i--)
		Max_Heapify(A, i, HEAP_SIZE);
}

//
void print(int* A)
{
	int i;
	for(i = 0; i < HEAP_SIZE; i++)
		printf("%d ", A[i]);
	printf("\n");
}

// heap sort
void HeapSort(int* A, int heap_size)
{
	Build_Max_Heap(A);
	int temp, i;
	for(i = heap_size-1; i > 0; i--)
	{
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		Max_Heapify(A, 0, i);
	}
	print(A);
}

int main()
{
	int A[HEAP_SIZE] = {19, 1, 10, 14, 16, 4, 7, 9, 3, 2, 8, 5};
	HeapSort(A, HEAP_SIZE);
	
	return 0;
}
