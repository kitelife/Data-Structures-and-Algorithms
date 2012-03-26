/*
 * queue.h
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

#include <stdlib.h>
#include <stdio.h>

#define OK	0
#define ERROR	1
#define OVERFLOW	-1

typedef int Status;
typedef int QElemType;

typedef struct QNode {
	QElemType	data;
	struct	QNode	*next;
}QNode;

typedef struct{
	QNode *front;	// 队头指针
	QNode *rear;	// 队尾指针
}LinkQueue;

Status InitQueue(LinkQueue *);

Status DestroyQueue(LinkQueue *);

Status EnQueue(LinkQueue *, QElemType);

Status DeQueue(LinkQueue *, QElemType *);