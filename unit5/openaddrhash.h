#ifndef _ELEMENT_H
#define _ELEMENT_H
typedef int Element;
#endif

#ifndef _OPENADDRHASH_H
#define _OPENADDRHASH_H
#define Hash1(key, size) key%size
#define Hash2(key) 7-(key%7)
typedef struct HashEntry* Position;
enum KindOfEntry {Legitimate, Empty, Deleted};
struct HashEntry{
	Element Element;
	enum KindOfEntry Info;
};
typedef struct HashEntry Cell;
typedef struct HashTableStr* HashTable;
typedef unsigned int HashIndex;
struct HashTableStr {
	unsigned int TableSize;
	Cell* Cells;
};
HashTable CreateHashTable(unsigned int TableSize);
HashIndex HashTableFind(HashTable H, int key);
HashIndex HashTableInsert(HashTable H, int key);
void HashTableInit(HashTable H);
void HashTableDelete(HashTable H, int key);
#endif
