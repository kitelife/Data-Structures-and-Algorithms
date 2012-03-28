#include "sstring.h"
#include "kmp.h"

int main()
{
	SString mainstr = "aaabaaaab";
	char *chars = "aaaab";
	int len = strlen(chars);
	int temp = len;
	SString paternstr;
	paternstr[0] = len;
	char *p = paternstr + 1;
	char *ch = chars;
	while(temp)
	{
		*p++ = *ch++;
		temp--;
	}
	int *next =(int *)malloc(MAXSTRLEN * sizeof(int));
	get_next(paternstr, next);
	while(len)
	{
		printf("%d\n", next[len]);
		len--;
	}
	printf("\n%d\n",Index_KMP(mainstr, paternstr, 1, next));
	return 0;
}

