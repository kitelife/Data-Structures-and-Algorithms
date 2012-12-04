#include <stdio.h>

int reverse_somebits(int a, int begin, int end)
{
	return a^((1<<end)|((1<<end)-1))^((1<<begin)-1);
}

void ten_to_two(int a)
{
	if(a < 2)
		printf("%d", a);
	else{
		 ten_to_two(a/2);
		 printf("%d", a%2);
	}
}

int main()
{
	int a = 0b1001101;
	int begin = 2, end = 5;
	ten_to_two(reverse_somebits(a, begin, end));
	printf("\n");
	return 0;
}
