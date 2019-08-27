#include<stdio.h>
#include<stdlib.h>
#include "..//utils/utils.h"
#include "insertionsort.h"
#include "shellsort.h"
#define NUMBERS_COUNT 10
void PrintNumbersArray(int* numbers, int count);
int* CreateNumbersArray(int min, int max, int count);
void ClearNumbersArray(int* numbers);

int main()
{
	int* numbers;

	// insertion sort
	numbers = CreateNumbersArray(0, 99, NUMBERS_COUNT);
	printf("\nInsertion sort\n");
	PrintNumbersArray(numbers, NUMBERS_COUNT);
	InsertionSort(numbers, NUMBERS_COUNT);
	printf("\n");
	PrintNumbersArray(numbers, NUMBERS_COUNT);
	ClearNumbersArray(numbers);

	// shell sort
	numbers = CreateNumbersArray(0, 99, NUMBERS_COUNT);
	printf("\nShell sort\n");
	PrintNumbersArray(numbers, NUMBERS_COUNT);
	ShellSort(numbers, NUMBERS_COUNT);
	printf("\n");
	PrintNumbersArray(numbers, NUMBERS_COUNT);
	ClearNumbersArray(numbers);

	return 0;
}

int* CreateNumbersArray(int min, int max, int count)
{
	int* numbers;
	int i, d;

	numbers = (int*)malloc(sizeof(int) * count);
	if (numbers == NULL)
	{
		fprintf(stderr, "out of memory");
		exit(EXIT_FAILURE);
	}

	d = max - min;
	for (i = 0; i < count; i++)
		numbers[i] = (int)((float)i/(float)count * d + min);

	return numbers;
}

void ClearNumbersArray(int* numbers)
{
	free(numbers);
}

void PrintNumbersArray(int* numbers, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		if (i != 0)
		{
			printf(", ");
		}
		printf("%02i", numbers[i]);
	}
}
