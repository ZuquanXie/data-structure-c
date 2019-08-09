#include<stdio.h>
#include<time.h>

long int fn1(int n);

long int fn2(int n);

long int fn3(int n);

long int fn4(int n);

long int fn5(int n);

long int fn6(int n);

int main()
{
	int i, n;

	printf("%-9s", "n");
	for (i = 1; i < 7; i++)
		printf("fn(%i)        ", i);
	putchar('\n');

	n = 1;
	for (i = 0; i < 7; i++)
	{
		printf(
			"%-7i  %-12li  %-12li  %-12li  %-12li  %-12li  %-12li\n",
			n,
			fn1(n),
			fn2(n),
			fn3(n),
			fn4(n),
			fn5(n),
			fn6(n)
		);
		n = n * 10;
	}

	return 0;
}

long int fn1(int n)
{
	int i;
	unsigned long int sum;
	clock_t a, b;

	a = clock();
	sum = 0;
	for (i = 0; i < n; i++)
		sum++;
	b = clock();

	return b - a;
}

long int fn2(int n)
{
	int i, j;
	unsigned long int sum;
	clock_t a, b;

	a = clock();
	sum = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			sum++;
	b = clock();

	return b - a;
}

long int fn3(int n)
{
	int i, j;
	unsigned long int sum;
	clock_t a, b;

	a = clock();
	sum = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n * n; j++)
			sum++;
	b = clock();

	return b - a;
}

long int fn4(int n)
{
	int i, j;
	unsigned long int sum;
	clock_t a, b;

	a = clock();
	sum = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++)
			sum++;
	b = clock();

	return b - a;
}

long int fn5(int n)
{
	int i, j, k;
	unsigned long int sum;
	clock_t a, b;

	a = clock();
	sum = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < i * i; j++)
			for (k = 0; k < j; k++)
				sum++;
	b = clock();

	return b - a;
}

long int fn6(int n)
{
	int i, j, k;
	unsigned long int sum;
	clock_t a, b;

	a = clock();
	sum = 0;
	for (i = 1; i < n; i++)
		for (j = 1; j < i * i; j++)
			if(j % i == 0)
				for (k = 0; k < j; k++)
					sum++;
	b = clock();

	return b - a;
}
