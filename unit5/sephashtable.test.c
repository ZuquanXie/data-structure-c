#include<stdio.h>
#include<time.h>
#include "sephashtable.h"
#define TABLE_SIZE 10
#define KEY_COUNT 11
void ListTable(SepHashTable);

int main()
{
	int i;
	SepHashTable H;
	clock_t s;

	H = CreateSepHashTable(TABLE_SIZE);
	i = 0;
	while (i < KEY_COUNT)
	{
		SepHashInsert(H, i * i);
		i++;
	}

	ListTable(H);

	i = 0;
	while (i < KEY_COUNT)
	{
		SepHashTableDelete(H, i * i);
		printf("Delete %i-------------------\n", i * i);
		ListTable(H);
		i++;
		s = clock();
		while (clock() - s <= CLOCKS_PER_SEC)
			continue;
	}

	return 0;
}

void ListTable(SepHashTable H)
{
	unsigned int i;
	Position target;

	i = 0;
	while (i < H->TableSize)
	{
		printf("%i:", i);
		target = H->Lists[i];
		while (target != NULL)
		{
			printf(" %i,", target->Element);
			target = target->Next;
		}
		putchar('\n');
		i++;
	}
}