#include<stdio.h>
#include<time.h>

void timeUsage(unsigned long int n);

int main()
{
	clock_t a;

	printf("CLOCKS_PER_SEC: %li\n", CLOCKS_PER_SEC);
	putchar('\n');
	printf("%-18s%-20s\n", "number", "clocks");
	timeUsage(10);
	putchar('\n');

	return 0;
}

void timeUsage(unsigned long int n)
{
	clock_t a, b;
	double result;

	a = clock();
	result = n / 2;
	b = clock();
	printf("%-16lu: %-20li\n", n, b - a);

	if (n >= 1000000000000000)
		return;

	timeUsage(n * 10);
}
