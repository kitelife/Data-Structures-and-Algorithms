//      roundRobinQueue.c
//      
//      Copyright 2012 xiayf <xiayf@debian>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.

#include "roundRobinQueue.h"

Status InitQueue(SqQueue *Q)
{
	Q->base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if(! Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	
	return OK;
}

int QueueLength(SqQueue *Q)
{
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e)
{
	if((Q->rear + 1) % MAXQSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
	if(Q->front == Q->rear)
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	
	return OK;
}

