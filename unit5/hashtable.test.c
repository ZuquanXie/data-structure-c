#include<stdio.h>
#include<stdlib.h>
#include "hash.h"
#define TABLE_SIZE 32

int main()
{
	printf("%-5s  %-10s\n", "key", "HashIndex");
	printf("%-5s  %-10i\n", "name", Hash("name", TABLE_SIZE));
	printf("%-5s  %-10i\n", "cont", Hash("cont", TABLE_SIZE));
	printf("%-5s  %-10i\n", "cent", Hash("cent", TABLE_SIZE));
	printf("abc%c\n", 127);

	return 0;
}
