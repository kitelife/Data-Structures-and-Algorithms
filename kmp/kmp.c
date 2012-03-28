#include "sstring.h"

int Index_KMP(SString S, SString T, int pos, int *next)
{
	// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的
	// KMP算法。其中，T非空，1<=pos<=StrLength(S)
	int i = pos;
	int j = 1;
	while(i <= S[0] && j <= T[0]){
		if(j == 0 || S[i] == T[j]){
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if(j > T[0])
		return i - T[0];
	else
		return 0;
}// Index_KMP

void get_next(SString T, int *next)
{
	// 求模式串T的next函数值并存入数组next
	int i = 1;
	next[1] = 0;
	int j = 0;
	while(i < T[0]){
		if(j == 0 || T[i] == T[j]){
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}// get_next

// 改写后的get_next函数
void get_next2(SString T, int *next)
{
	// 和get_next函数的区别是，如果T的长度为1，则get_next2函数的结果是不对的
	int i = 2;
	next[1] = 0;
	next[2] = 1;
	int j = 1;
	while(i < T[0])
	{
		if(T[i]==T[j]){
			++i;
			++j;
			next[i]=j;
		}
		else
		{
			j = next[j];
		}
	}
}

// 修正后的get_next函数
void get_nextval(SString T, int *nextval)
{
	int i = 1;
	nextval[1] = 0;
	int j = 0;
	while(i < T[0])
	{
		if(j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			if(T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}// get_nextval
