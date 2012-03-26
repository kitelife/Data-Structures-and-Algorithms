 /*
  * linkStack.c
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

Status InitStack(simpleStack *st)
{
	st->top = NULL;
	return OK;
}

Status Push(simpleStack *st, ElemType e)
{
	StNode *node = (StNode *)malloc(sizeof(StNode));
	node->content = e;
	node->next = st->top;
	st->top = node;

	return OK;
}

Status Pop(simpleStack *st, ElemType *e)
{
	if(st->top)
	{
		*e = st->top->content;
		StNode *nodepop = st->top;
		st->top = st->top->next;
		free(nodepop);

		return OK;
	}
	return ERROR;
}

Status GetTop(simpleStack *st, ElemType *e)
{
	*e = st->top->content;

	return OK;
}
