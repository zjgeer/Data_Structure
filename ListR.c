/*
ADT 线性表(List)
Data
	线性表的数据对象集合为（a1,a2,……,an），每个元素的类型均为DataType.
Operation
	InitList(*L):	初始化操作，建立一个空的线性表L.
	ListEmpty(L):	若线性表为空，返回True，否则返回false.
	ClearList(*L):	线性表清空。
	GetElem(L,i,*e):取出第i个元素。
	LocateElem(L,e):查找。
	ListInsert(*L,i,e):插入。
	ListDelete(*L,i,*e):删除。
	ListLength(L):	线性表元素个数。
endADT
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE	20
#define OK		1
#define ERROR	0
#define TRUE	1
#define FALSE	0

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

typedef struct Node
{
	ElemType data;
	struct Node *next;
	
}Node;

typedef struct Node *LinkList;

void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i = 0;i < n;i++)
	{
		P = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList *L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	
	r = *L;
	
	for(i = 0;i < n;i++)
	{
		P = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
/*
	Status是函数的类型，其值是函数结果状态代码，如OK
	初始条件：顺序线性表L已经存在，1 ≤ i ≤ ListLength(L)
	操作结果：用e返回L中的第i个数据元素的值
*/
Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length == 0 || i < 1 || i > L.length)
	{
		return ERROR;
	}
	*e = L.data[i - 1];
	return OK;
}

Status GetElemChain(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;

	p = L->next;
	j = 1;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
	{
		return ERROR;
	}
	*e = p->data;
	return OK;

}





/*
	初始条件：顺序线性表L已经存在，1 ≤ i ≤ ListLength(L)
	操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
*/
Status ListInsert(SqList *L,int i,ElemType e)
{
	int k;
	if(L->length == MAXSIZE)
	{
		return ERROR;
	}
	if(i < 1 || i > L->length + 1)
	{
		return ERROR;
	}
	if(i <= L->length)
	{
		for(k = L->length - 1;k >= i -1;k--)
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length++;
	return OK;
}

Status ListInsertChain(LinkList L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
	{
		return ERROR;
	}
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	
	return OK;
}
/*
	初始条件：顺序线性表L已经存在，1 ≤ i ≤ ListLength(L)
	操作结果：删除L中第i个数据元素，并用e返回其值，L的值减1
*/
Status ListDelete(SqList *L,int i,ElemType *e)
{
	int k;
	
	if(L->length == 0 || i < 1 || i > L->length)
	{
		return ERROR;
	}
	*e = L->data[i - 1];
		
	if(i < L->length)
	{
		for(k = i;k < L->length;k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}

Status ListDeleteChain(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p,q;
	p = L;

	j = 1;
	while(p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i)
	{
		return ERROR;
	}
	q = p->next;
	
	p->next = q->next;
	*e = q->data;
	free(q);

	return OK;
}

int main(int argc,char *argv[])
{
	int i;
	SqList MyList;
	
	MyList.length = 5;
	for(i = 0;i < MyList.length;i++)
	{
		MyList.data[i] = i;
	}
	
	printf("The MyList is:\n");
	
	for(i = 0;i < MyList.length;i++)
	{
		printf("MyList.data[%d] = %d\n",i,MyList.data[i]);
	}

	if(ListInsert(&MyList,3,34) == OK)
	{
		printf("List Insert OK!\n");
	}
	else
	{
		printf("List Insert ERROR!\n");
	}
	
	printf("The MyList is:\n");
	
	for(i = 0;i < MyList.length;i++)
	{
		printf("MyList.data[%d] = %d\n",i,MyList.data[i]);
	}

	return 0;
}

