/***************************************************************************
 * 
  * sqStack.h
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

#include<stdlib.h>
#include<stdio.h>

#define STACK_INIT_SIZE	10	//存储空间初始分配量
#define	STACKINCREMENT	10	//存储空间分配增量

typedef int SElemType;
typedef int Status;

#define	OK	0
#define	ERROR	1
#define	OVERFLOW	-1

typedef struct {
	SElemType	*base;	// 在栈构造之前和销毁之后，base的值为NULL
	SElemType	*top;	// 栈顶指针
	int	stacksize;	//当前已分配的存储空间，以元素为单位
}SqStack;

Status InitStack(SqStack *S);

Status GetTop(SqStack S, SElemType *e);

Status Push(SqStack *S, SElemType e);

Status Pop(SqStack *S, SElemType *e);

Status StackEmpty(SqStack *S);