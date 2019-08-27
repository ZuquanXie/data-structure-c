#include<stdio.h>
#include<stdlib.h>
#include "insertionsort.h"

int* InsertionSort(int* arr, int count)
{
	int i, j, tmp;

	for (i = 1; i < count; i++)
	{
		tmp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
			arr[j] = arr[j - 1];
		arr[j] = tmp;
	}

	return arr;
}