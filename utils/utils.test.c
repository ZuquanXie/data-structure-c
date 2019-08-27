#include<stdio.h>
#include<stdlib.h>
#include "utils.h"
#define Wait(x) WaitClocks(x * CLOCKS_PER_SEC)

int main()
{
	int i, j, k;

	i = 0;
	while (i < 10)
	{
		// just for windows console
		j = system("cls");
		printf("------------\n");
		printf("Count: %02i\n", i + 1);
		printf("Price: %02i\n", i * 3);
		printf("------------\n");
		Wait(1);
		i++;
	}
	Wait(2);
	return 0;
}