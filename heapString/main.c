/*
 * main.c
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

int main()
{
	HString S;
	char *s = "123abcmijk";
	if(StrInit(&S, s))
		return 1;
	printf("%s, %d\n", S.ch, S.length);

	HString T;
	char *t = "def456";
	if(StrInit(&T, t))
		return 1;
	printf("%s, %d\n", T.ch, T.length);
	
	if(StrInsert(&S, 2, T))
		return 1;
	printf("%s,%d\n", S.ch, S.length);
	HString H;
	StrAssign(&H, s);
	printf("%s, %d\n", H.ch, H.length);
	return 0;
}