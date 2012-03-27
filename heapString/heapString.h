/*
 * heapString.h
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
/*
 * 堆分配存储表示的串
 * 以一组地址连续的存储单元存放串值字符序列，但它们的存储空间是在程序执行过程中
 * 动态分配而得。
 */

#include <stdlib.h>
#include <stdio.h>

#define OK	0
#define ERROR	1
#define OVERFLOW	-1
#define INITSIZE	10

typedef int Status;

typedef struct {
	char *ch;		// 若是非空串，则按串长分配存储区，否则ch为NULL
	int length;		// 串长度
}HString;

Status StrInit(HString *, char *);

Status StrInsert(HString *, int, HString);

Status StrAssign(HString *, char *);

int StrLength(HString);

int StrCompare(HString, HString);

Status ClearString(HString *);

Status Concat(HString *, HString, HString);

Status SubString(HString *, HString, int, int);

int Index(HString, HString, int);
