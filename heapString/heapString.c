/*
 * heapString.c
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
#include "heapString.h"

// 其实和StrAssign函数的功能是一样的。
Status StrInit(HString *S, char *chs)
{
	char *p = chs;
	int len = 0;
	while(*p++)
		len++;
	if(len <= INITSIZE){
		// 为'\0'另外申请一个空间，所以得申请INITSIZE个char的内存空间。
		S->ch = (char *)malloc((INITSIZE+1) * sizeof(char));
		p = chs;
		char *strp = S->ch;
		while(*p)
			*strp++ = *p++;
		S->length = len;

		return OK;
	}

	return ERROR;
}

Status StrInsert(HString *S, int pos, HString T)
{
	// 1 <= pos <= StrLength(S)+1。在串S的第pos个字符之前插入串T。
	if(pos < 1 || pos > (S->length + 1))
		return ERROR;
	if(T.length){ // T非空，则重新分配空间，插入T
		// 得为'\0'提供一个空间
		if(!(S->ch = (char *)realloc(S->ch, (S->length + T.length+1)*sizeof(char))))
			exit(OVERFLOW);
		int i;
		for(i = (S->length)-1; i >= pos-1; --i) // 为插入T而腾出位置
			*(S->ch + i + T.length) = *(S->ch + i);
		for(i = 0; i <= (T.length-1); i++)
			*(S->ch + (pos-1) + i) = *(T.ch + i);
		S->length += T.length;
	}
	return OK;
}// StrInsert

Status StrAssign(HString *T, char *chars)
{
	//生成一个其值等于串常量chars的串T
	//if(T->ch)
	//	free(T->ch);	// 释放T原有空间
	int i;
	char *c;
	for(i=0, c=chars; *c; ++i, ++c); // 求chars的长度i
	if(!i){
		T->ch = NULL;
		T->length = 0;
	}else{
		if(!(T->ch = (char *)malloc(i * sizeof(char))))
			exit(OVERFLOW);
		int j;
		for(j = 0; j < i; j++)
			T->ch[j] = chars[j];
		T->length = i;
	}

	return OK;
}// StrAssign

int StrLength(HString S){
	// 返回S的元素个数，称为串的长度
	return S.length;
}// StrLength

int StrCompare(HString S, HString T)
{
	// 若S>T, 则返回值>0; 若S=T，则返回值=0；若S<T,则返回值<0
	int i;
	for(i=0; i<S.length && i<T.length; ++i)
		if(S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	return S.length - T.length;
}//StrCompare

Status ClearString(HString *S)
{
	// 将S清为空串
	if(S->ch){
		free(S->ch);
		S->ch = NULL;
	}
	S->length = 0;
	return OK;
}// clearString

Status Concat(HString *T, HString S1, HString S2)
{
	// 用T返回由S1和S2联接而成的新串
	if(T->ch)
		free(T->ch);	// 释放旧空间
	if(!(T->ch = (char *)malloc((S1.length + S2.length + 1)*sizeof(char))))
		exit(OVERFLOW);
	int i;
	for(i=0; i<S1.length; i++)
		T->ch[i] = S1.ch[i];
	T->length = S1.length + S2.length;
	for(i=0; i<S2.length; i++)
		T->ch[i+S1.length] = S2.ch[i];

	return OK;
}// Concat

Status SubString(HString *Sub, HString S, int pos, int len)
{
	// 用Sub返回串S的第pos个字符起长度为len的子串
	// 其中，1<=pos<=StrLength(S)且0<=len<=StrLength(S)-pos+1
	if(pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
		return ERROR;
	if(Sub->ch)
		free(Sub->ch);
	if(!len){
		Sub->ch = NULL;
		Sub->length = 0;
	}
	else{
		Sub->ch = (char *)malloc(len * sizeof(char));
		int i;
		for(i=0; i < len; i++)
			Sub->ch[i] = S.ch[pos-1 + i];
		Sub->length = len;
	}
	return OK;
}// SubString

int Index(HString S, HString T, int pos)
{
	// T为非空串。若主串S中第pos个字符之后存在与T相等的子串，
	// 则返回第一个这样的子串在S中的位置，否则返回0

	if(pos > 0)
	{
		int n = StrLength(S);
		int m = StrLength(T);
		int i = pos;
		HString sub;
		while(i <= n-m+1){
			SubString(&sub, S, i, m);
			if(StrCompare(sub, T) != 0)
				++i;
			else
				return i;
		}// while
	}//if
	return 0;
}// Index
