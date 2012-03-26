/*
 * queue.c
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

#include "queue.h"

Status InitQueue(LinkQueue *Q)
{
	// 构造一个空队列Q
	Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
	if(! Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;

	return OK;
}// InitQueue;

Status DestroyQueue(LinkQueue *Q)
{
	// 销毁队列Q
	while(Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}

	return OK;
}// DestroyQueue

Status EnQueue(LinkQueue *Q, QElemType e)
{
	// 插入元素e为Q的新的队尾元素
	QNode *p = (QNode *)malloc(sizeof(QNode));
	if(! p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;

	return OK;
}// EnQueue

Status DeQueue(LinkQueue *Q, QElemType *e)
{
	// 若队列不空，则删除Q的对头元素，用e返回其值，并返回OK;
	// 否则返回ERROR
	if(Q->front == Q->rear)
		return ERROR;	
	QNode *p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p)
		Q->rear = Q->front;
	free(p);

	return OK;
}// DeQueue