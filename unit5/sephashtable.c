#include<stdio.h>
#include<stdlib.h>
#include "sephashtable.h"

HashIndex Hash(int key, unsigned int TableSize)
{
	return key % TableSize;
}

SepHashTable CreateSepHashTable(unsigned int TableSize)
{
	List * Lists;
	SepHashTable H;
	unsigned int i;

	Lists = (List *)malloc(sizeof(List) * TableSize);
	if (Lists == NULL)
	{
		fprintf(stderr, "out of memory");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < TableSize)
	{
		Lists[i] = NULL;
		i++;
	}

	H = (SepHashTable)malloc(sizeof(struct StrSepHashTable));
	if (H == NULL)
	{
		fprintf(stderr, "out of memory");
		exit(EXIT_FAILURE);
	}
	H->TableSize = TableSize;
	H->Lists = Lists;

	return H;
}

void SepHashInsert(SepHashTable H, int key)
{
	HashIndex index;
	Position newNode, target;

	newNode = (Position)malloc(sizeof(struct ListNode));
	if (newNode == NULL)
	{
		fprintf(stderr, "out of memory");
		exit(EXIT_FAILURE);
	}

	index = Hash(key, H->TableSize);
	target = H->Lists[index];
	if (target == NULL)
	{
		H->Lists[index] = newNode;
		newNode->Next = NULL;
	}
	else
	{
		while (target != NULL && target->Element != key)
			target = target->Next;
		// repeated key
		if (target == NULL)
		{
			newNode->Next = H->Lists[index];
			H->Lists[index] = newNode;
		}

	}
	newNode->Element = key;
}

void SepHashTableDelete(SepHashTable H, int key)
{
	Position prev, target;
	HashIndex index;

	index = Hash(key, H->TableSize);
	prev = NULL;
	target = H->Lists[index];
	while (target != NULL && target->Element != key)
	{
		prev = target;
		target = target->Next;

	}
	if (target == NULL)
	{
		fprintf(stderr, "wrong delete target");
		exit(EXIT_FAILURE);
	}
	if (prev == NULL)
		H->Lists[index] = target->Next;
	else
		prev->Next = target->Next;
	free(target);
}
