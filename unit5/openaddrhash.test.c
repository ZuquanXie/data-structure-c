#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "openaddrhash.h"
#define Wait(x) WaitClocks(x*CLOCKS_PER_SEC)
void WaitClocks(clock_t t);
void CleanLines(unsigned int lineCount);
void ListTable(HashTable H);

int main()
{
	HashTable H;
	unsigned int i, lineCount;
	int numbers[] = {6, 23, 17, 32, 8, 7, 19, 13, 35, 27, 28, 31, 5, 12, 37, 1, 14};

	H = CreateHashTable(39);
	i = 0;
	lineCount = 12;
	while (i < 17)
	{
		HashTableInsert(H, numbers[i]);
		CleanLines(lineCount);
		printf("Insert: %02i\n", numbers[i]);
		ListTable(H);
		i++;
		Wait(2);
	}

	return 0;
}

void ListTable(HashTable H)
{
	unsigned int i, j;

	i = 0;
	while (i < H->TableSize)
	{
		j = 0;
		while (j < 4 && i < H->TableSize)
		{
			if (H->Cells[i].Info == Empty)
				printf("%02i: %s", i, "--");
			else
				printf("%02i: %02i", i, H->Cells[i].Element);
			printf("    ");
			j++;
			i++;
		}
		printf("\n");
	}
}

void CleanLines(unsigned int lineCount)
{
	unsigned int i;

	i = 0;
	while (i < lineCount)
	{
		putchar('\r');
		putchar('\b');
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
