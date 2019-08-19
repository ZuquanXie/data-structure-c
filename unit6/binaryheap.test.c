#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "binaryheap.h"
#define Wait(x) WaitClocks(x*CLOCKS_PER_SEC)
void WaitClocks(clock_t t);
void CleanLines(int count);
void ListHeap(BinaryHeap H);

int main()
{
	BinaryHeap H;
	int i;
	int numbers[10] = { 4, 14, 23, 11, 5, 8, 19, 3, 15, 17 };

	H = InitializeBinaryHeap(19);
	i = 0;
	while (i < 10)
	{
		BinaryHeapInsert(H, numbers[i]);
		CleanLines(1);
		ListHeap(H);
		i++;
		Wait(1);
	}

	i = 0;
	while (i < 10)
	{
		printf("\nDelete %02i", BinaryHeapDeleteMin(H));
		ListHeap(H);
		i++;
		Wait(1);
	}

	return 0;
}

void CleanLines(int count)
{
	int i;

	i = 0;
	while (i < count)
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
	while (clock() - s < t)
		continue;
}

void ListHeap(BinaryHeap H)
{
	int i;

	printf("\nElements:");
	i = 0;
	while (i < H->Size + 1)
	{
		printf("  %02i", H->Elements[i]);
		i++;
	}
}