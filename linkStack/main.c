/*
 * main.c.c
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

#include "linkStack.h"

int main()
{
	simpleStack *st = (simpleStack *)malloc(sizeof(simpleStack));
	InitStack(st);
	int inputCount, input, popOut=0;
	printf("inputCount: ");
	scanf("%d", &inputCount);
	while(inputCount){
		scanf("%d", &input);
		Push(st, input);
		inputCount --;
	}
	while(st->top){
		Pop(st, &popOut);
		printf("%d\n", popOut);
	}

	return 0;
}
