/***************************************************************************
 * 
  * sqStack.c
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
 *
 *  Mon March 26 14:36:16 2012
 *  Copyright  2012  xiayf
 ****************************************************************************/
#include "sqStack.h"

Status InitStack(SqStack *S)
{
	// 构造一个空栈
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S->base)
		exit(OVERFLOW);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;

	return OK;
}// InitStack

Status GetTop(SqStack S, SElemType *e)
{
	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if(S.top == S.base)
		return ERROR;
	*e = *(S.top-1);
	return OK;
}// GetTop

Status Push(SqStack *S, SElemType e)
{
	// 插入元素e为新的栈顶元素
	if(S->top - S->base >= S->stacksize){
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(SElemType));
		if(! S->base)
			exit(OVERFLOW);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}// Push

Status Pop(SqStack *S, SElemType *e)
{
	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S->top == S->base)
		return ERROR;
	*e = * --S->top;
	return OK;
}// Pop

Status StackEmpty(SqStack *S){
	return S->top == S->base;
}