#include<stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 0
#define ERROR 1
#define OVERFLOW -1

typedef int ElemType;
typedef int Status;

typedef struct{
	ElemType	*elem;	//存储空间基地址
	int			length;	//当前长度
	int			listsize;	//当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;

Status InitList_Sq(SqList *);

Status ListInsert_Sq(SqList *, int, ElemType);

Status ListDelete_Sq(SqList *, int, ElemType *);

Status compare(ElemType, ElemType);

int LocateElem_Sq(SqList, ElemType, Status (*compare)(ElemType, ElemType));

void MergeList_Sq(SqList, SqList, SqList *);

int partition(SqList *, int, int);

void QSort(SqList *, int, int);

void QSortList_Sq(SqList *);
