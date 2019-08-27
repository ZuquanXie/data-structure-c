#include "shellsort.h"

void ShellSort(int* numbers, int count)
{
	int increment, i, j, temp;

	for (increment = count / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < count; i++)
		{
			temp = numbers[i];
			for (j = i; j >= increment && temp < numbers[j - increment]; j-= increment)
				numbers[j] = numbers[j - increment];
			numbers[j] = temp;
		}
	}
}