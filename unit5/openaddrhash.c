#include<stdio.h>
#include<stdlib.h>
#include "openaddrhash.h"

HashTable CreateHashTable(unsigned int TableSize)
{
	HashTable H;
	Cell newCell;
	Cell* Cells;
	int i;

	H = (HashTable)malloc(sizeof(struct HashTableStr));
	Cells = (Cell*)malloc(sizeof(Cell) * TableSize);
	if (H == NULL || Cells == NULL)
	{
		fprintf(stderr, "out of memory");
		exit(EXIT_FAILURE);
	}

	i = 0;
	while (i < TableSize)
	{
		Cells[i].Element = 0;
		Cells[i].Info = Empty;
		i++;
	}
	H->TableSize = TableSize;
	H->Cells = Cells;

	return H;
}

HashIndex HashTableFind(HashTable H, int key)
{
	HashIndex index;

	index = Hash1(key, H->TableSize);
	if (H->Cells[index].Info != Legitimate)
		return index;

	index = Hash2(key);
	if (H->Cells[index].Info != Legitimate)
		return index;

	return -1;
}

HashIndex HashTableInsert(HashTable H, int key)
{
	HashIndex index;

	index = HashTableFind(H, key);

	if (index == -1)
		return -1;

	H->Cells[index].Element = key;
	H->Cells[index].Info = Legitimate;

	return index;
}

void HashTableInit(HashTable H)
{
	int i;

	i = 0;
	while (i < H->TableSize)
	{
		H->Cells[i].Element = 0;
		H->Cells[i].Info = Empty;
		i++;
	}
}

void HashTableDelete(HashTable H, int key)
{
	HashIndex index;

	index = Hash1(key, H->TableSize);
	if (H->Cells[index].Info == Legitimate)
	{
		if (H->Cells[index].Element != key)
			index = Hash2(key);
		if (H->Cells[index].Element == key)
		{
			H->Cells[index].Info = Deleted;
		}
	}
}