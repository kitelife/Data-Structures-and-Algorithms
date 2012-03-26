 /*
  * linkStack.h
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
#include<stdlib.h>
#include<stdio.h>

#define OK	0
#define ERROR	1
#define OVERFLOW	-1

typedef int Status;
typedef int ElemType;

typedef struct stNode {
	ElemType content;
	struct stNode *next;
}StNode;

typedef struct simpleSt{
	StNode *top;
}simpleStack;

Status InitStack(simpleStack *st);

Status Push(simpleStack *st, ElemType e);

Status Pop(simpleStack *st, ElemType *e);

Status GetTop(simpleStack *st, ElemType *e);
