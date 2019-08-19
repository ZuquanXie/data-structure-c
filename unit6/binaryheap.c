#include<stdio.h>
#include<stdlib.h>
#include "binaryheap.h"
#ifndef MIN_DATA
#define MIN_DATA 0
#define MAX_DATA 999999
#endif

BinaryHeap InitializeBinaryHeap(unsigned int Capacity)
{
	BinaryHeap H;
	Element* Elements;

	H = (BinaryHeap)malloc(sizeof(struct BinaryHeapStruct));
	Elements = (Element*)malloc(sizeof(Element) * (Capacity + 1));
	if (H == NULL || Elements == NULL)
	{
		fprintf(stderr, "out of memory");
		exit(EXIT_FAILURE);
	}

	H->Capacity = Capacity;
	H->Size = 0;
	H->Elements = Elements;
	H->Elements[0] = MIN_DATA;

	return H;
}

void BinaryHeapInsert(BinaryHeap H, Element ele)
{
	int i, j;
	
	i = H->Size + 1;
	if (i > H->Capacity)
	{
		fprintf(stderr, "heap is full");
		exit(EXIT_FAILURE);
	}
	j = (int)(i / 2);
	while (ele < H->Elements[j])
	{ 
		H->Elements[i] = H->Elements[j];
		i = j;
		j = (int)(i / 2);
	}
	H->Elements[i] = ele;
	H->Size += 1;
}

Element BinaryHeapDeleteMin(BinaryHeap H)
{
	int i, j;
	Element result, last;

	i = 1;
	result = H->Elements[i];
	last = H->Elements[H->Size];
	H->Elements[H->Size] = MAX_DATA;
	while (i * 2 <= H->Size)
	{
		j = i * 2;
		if (j != H->Size && H->Elements[j] > H->Elements[j + 1])
			j++;
		if (last < H->Elements[j])
			break;
		H->Elements[i] = H->Elements[j];
		i = j;
	}
	H->Elements[i] = last;
	H->Size -= 1;

	return result;
}