#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "openaddrhash.h"
#define Wait(x) WaitClocks(x*CLOCKS_PER_SEC)
void WaitClocks(clock_t t);
void ListTable(HashTable H);

int main()
{
	HashTable H;

	H = CreateHashTable(13);
	HashTableInsert(H, 23);
	ListTable(H);
	Wait(1);
	HashTableInsert(H, 21);
	ListTable(H);
	Wait(1);
	HashTableInsert(H, 83);
	ListTable(H);

	return 0;
}

void ListTable(HashTable H)
{
	int i;

	i = 0;
	while (i < H->TableSize)
	{
		printf("%i: %i\n", i, H->Cells[i].Element);
		i++;
	}
}

void WaitClocks(clock_t t)
{
	clock_t s;

	s = clock();
	while (clock() - s <= t)
	{
		continue;
	}
}
