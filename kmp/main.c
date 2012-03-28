#include "sstring.h"
#include "kmp.h"

int main()
{
	SString mainstr = "aaabaaaab";
	unsigned char *chars = (unsigned char *)"aaaab";
	unsigned char *chstemp = chars;
	int len = 0;
	while(*chstemp){
		len ++;
		chstemp++;
	}
	int temp = len;
	int temp2 = len;
	
	SString paternstr;
	paternstr[0] = len;
	
	unsigned char *p = paternstr + 1;
	unsigned char *ch = chars;
	while(temp)
	{
		*p++ = *ch++;
		temp--;
	}
	*p = '\0';

	int *next =(int *)malloc(MAXSTRLEN * sizeof(int));
	get_next(paternstr, next);
	while(len)
	{
		printf("%d\n", next[len]);
		len--;
	}
	printf("\n%d\n",Index_KMP(mainstr, paternstr, 1, next));

	int *nextval = (int *)malloc(MAXSTRLEN * sizeof(int));
	get_nextval(paternstr, nextval);
	while(temp2)
	{
		printf("%d\n", nextval[temp2]);
		temp2--;
	}
	printf("\n%d\n", Index_KMP(mainstr, paternstr, 1, nextval));
	return 0;
}

