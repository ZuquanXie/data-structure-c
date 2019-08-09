#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<math.h>

typedef unsigned long int ele;

void createSourceData(ele table[], const ele count);

ele search(const ele target, const ele table[], const ele count);

ele primary_search(const ele target, const ele table[], const ele count);

ele binary_search(const ele target, const ele table[], const ele count);

int main()
{
	ele count = 1e8;
	ele * table;

	// 分配内存
	table = (ele *) malloc(count * sizeof(ele));
	printf("* table: %p\n\n", table);
	createSourceData(table, count);
	search(2432, table, count);

	// 释放内存
	free(table);

	return 0;
}

void createSourceData(ele table[], const ele count)
{
	ele i;
	clock_t a, b;

	printf("data creating...\n");
	a = clock();
	for (i = 0; i < count; i++)
		table[i] = i;
	b = clock();
	printf("creating finished(%.4fs, %li clocks)\n", (double)((b - a) / CLOCKS_PER_SEC), b - a);
}

ele search(const ele target, const ele table[], const ele count)
{
	clock_t a, b;
	ele targetIndex;

	printf("\ntarget: %li, total: 10^%.0f\n", target, log10((double)(count)));

	// primary search
	putchar('\n');
	printf("primary searching begin...\n");
	a = clock();
	targetIndex = primary_search(target, table, count);
	b = clock();
	printf("primary searching finished(%.4fs, %li clocks)\n", (double)((b - a) / CLOCKS_PER_SEC), b - a);
	printf("result: %li\n", targetIndex);

	// binary search
	putchar('\n');
	printf("binary searching begin...\n");
	a = clock();
	targetIndex = binary_search(target, table, count);
	b = clock();
	printf("binary searching finished(%.4fs, %li clocks)\n", (double)((b - a) / CLOCKS_PER_SEC), b - a);
	printf("result: %li\n", targetIndex);

	return targetIndex;
}

ele primary_search(const ele target, const ele table[], const ele count)
{
	ele i, targetIndex;

	for(i = 0; i < count; i++)
	{
		if (table[i] == target)
			return i;
	}

	return targetIndex;
}

ele binary_search(const ele target, const ele table[], const ele count)
{
	ele targetIndex, headerIndex, footerIndex, mediumIndex;

	headerIndex = 0;
	footerIndex = table[count - 1];
	mediumIndex = footerIndex / 2;

	while(headerIndex != footerIndex)
	{
		if(table[mediumIndex] == target)
		{
			return mediumIndex;
		}
		if(table[mediumIndex] > target)
		{
			footerIndex = mediumIndex;
			mediumIndex = headerIndex + (footerIndex - headerIndex) / 2;
			continue;
		}

		if(table[mediumIndex] < target)
		{
			headerIndex = mediumIndex;
			mediumIndex = headerIndex + (footerIndex - headerIndex) / 2;
		}
	}

	return targetIndex;
}
