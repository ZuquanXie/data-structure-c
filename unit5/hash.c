#include "hash.h"

HashIndex Hash(char* key, int TableSize)
{
	unsigned int hashValue;

	hashValue = 0;
	while (*key != '\0')
	{
		hashValue = (hashValue << 5) + *key;
		key++;
	}

	return hashValue % TableSize;
}