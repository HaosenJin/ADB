#include"stdafx.h";
#include "stdlib.h"

void* aligned_malloc(size_t required_bytes, size_t alignment)
{
	void* p1;
	void** p2;
	int offset = alignment - 1 + sizeof(void*);
	if ((p1 = (void*)malloc(required_bytes + offset)) == NULL)
	{
		return NULL;
	}

	p2 = (void**)(((size_t)p1 + offset)&~(alignment - 1));
	p2[-1] = p1;
	return p2;
}

void aligned_free(void* p2)
{
	void* p1 = ((void**)p2)[-1];
	free(p1);
}

int** my2DAlloc(int rows, int cols)
{
	int** rowptr;
	int i;
	rowptr = (int**)malloc(rows*sizeof(int*));
	for (int i = 0; i < rows; i++)
	{
		rowptr[i] = (int*)malloc(cols*sizeof(int));
	}
	return rowptr;
}

void my2DDealloc(int** rowptr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		free(rowptr[i]);
	}
	free(rowptr);
}

int** my2DAlloc2(int rows, int cols)
{
	int head = rows*sizeof(int*);
	int body = rows*cols*sizeof(int);
	int** rowptr = (int**)malloc(head + body);
	if (rowptr == NULL)
		return NULL;
	int* buf = (int*)(rowptr + rows);
	for (int i = 0; i < rows; i++)
	{
		rowptr[i] = (int*)(buf + i*cols);
	}
	return rowptr;
}