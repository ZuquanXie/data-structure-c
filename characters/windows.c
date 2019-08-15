#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define WaitS(x) Wait(x*CLOCKS_PER_SEC);
void Wait(clock_t t);

int main()
{
	printf("\\r value: %i\n", '\r');
	printf("\\b value: %i\n", '\b');
	printf("a: string\n");
	WaitS(2);
	putchar('\r');
	WaitS(1);
	putchar('\b');
	WaitS(1);
	putchar('\r');
	WaitS(1);
	printf("b: string\n");

	WaitS(2);
	return 0;
}

void Wait(clock_t t)
{
	clock_t s;

	s = clock();
	while (clock() - s <= t)
		continue;
}