/*
 * conversion.c
 *
 * Copyright (C) 2012 - xiayf
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "sqStack.h"

void conversion();

int main()
{
	SqStack *S = (SqStack *)malloc(sizeof(SqStack));
	conversion(S);

	return 0;
}

void conversion(SqStack *S){
	// 对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数。
	InitStack(S);
	int N, e;
	scanf("%d",&N);
	while(N){
		Push(S, N % 8);
		N = N / 8;
	}
	while(!StackEmpty(S)){
		Pop(S, &e);
		printf("%d", e);
	}
	printf("\n");
}// conversion