#include "arrayList.h"

Status InitList_Sq(SqList *L)
{
	// 构造一个空的线性表L;
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(! L->elem)
		exit(OVERFLOW);
	L->length = 0;	// 空表长度为0
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
	// 在顺序线性表L中第i个位置之前插入新的元素e
	// i的合法值为1<=i<=ListLength_Sq(L)+1
	if(i < 1 || i > L->length + 1)
		return ERROR;
	if(L->length >= L->listsize){
		ElemType *newbase = (ElemType *)realloc(L->elem,
				(L->listsize + LISTINCREMENT)*sizeof(ElemType));
		if(! newbase)
			exit(OVERFLOW);
		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}

	ElemType *q = &(L->elem[i-1]);	//q为插入位置
	ElemType *p;
	// 插入位置及以后的元素右移
	for(p=&(L->elem[L->length-1]); p >= q; --p)
		*(p+1) = *p;
	*q = e;	// insert e
	++ L->length;
	return OK;
}

Status ListDelete_Sq(SqList *L, int i, ElemType *e)
{
	// 在顺序线性表L中删除第i个元素，并用e返回其值
	// i的合法值为1 <= i <= ListLength_Sq(L)
	if((i < 1) || (i > L->length))
		return ERROR;
	ElemType *p = &(L->elem[i-1]);
	*e = *p;
	ElemType *q = L->elem + L->length - 1;	//表尾元素的位置
	for(++p; p <= q; ++p)
		*(p-1) = *p;
	-- L->length;

	return OK;
}

Status compare(ElemType first, ElemType second)
{
	if(first >= second)
		return 1;
	else
		return 0;
}

int LocateElem_Sq(SqList L, ElemType e,
		Status (*compare)(ElemType, ElemType))
{
	// 在顺序线性表L中查找第1个值与e满足compare()的元素的位序
	// 若找到，则返回其在L中的位序，否则返回0
	int i = 1;
	ElemType *p = L.elem;
	while(i <= L.length && !(*compare)(*p++, e))
		++i;
	if(i <= L.length)
		return i;
	else
		return 0;
}

void MergeList_Sq(SqList La, SqList Lb, SqList *Lc)
{
	// 已知顺序线性表La和Lb的元素按值非递减排列
	// 归并La和Lb得到新的顺序线性表Lc,Lc的元素也是按值非递减排列
	ElemType *pa = La.elem;
	ElemType *pb = Lb.elem;
	Lc->listsize = Lc->length = La.length + Lb.length;
	ElemType *pc = Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
	if(! Lc->elem)
		exit(OVERFLOW);
	ElemType *pa_last = La.elem + La.length - 1;
	ElemType *pb_last = Lb.elem + Lb.length - 1;
	while(pa <= pa_last && pb <= pb_last){
		if(*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while(pa <= pa_last) *pc++ = *pa++;
	while(pb <= pb_last) *pc++ = *pb++;
}

int Partition(SqList *L, int low, int high)
{
	ElemType temp = L->elem[low];
	ElemType pivotkey = L->elem[low];
	while(low < high){
		while(low < high && L->elem[high] >= pivotkey)
			--high;
		L->elem[low] = L->elem[high];
		while(low < high && L->elem[low] <= pivotkey)
			++low;
		L->elem[high] = L->elem[low];
	}
		L->elem[low] = temp;
		return low;
}

void QSort(SqList *L, int low, int high)
{
	// 对顺序表L中的子序列L->elem[low...high]做快速排序
	if(low < high){
		int pivotloc = Partition(L, low, high);	// 一分为二
		QSort(L, low, pivotloc-1);
		QSort(L, pivotloc+1, high);
	}
}

void QSortList_Sq(SqList *L)
{
	QSort(L, 0, L->length-1);
}
