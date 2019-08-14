#ifndef _ELEMENT_H
#define _ELEMENT_H
typedef int Element;
#endif

#ifndef _SEPHASHTABLE_H
#define _SEPHASHTABLE_H
// List
typedef struct ListNode* Position;
typedef Position List;
struct ListNode {
	Element Element;
	Position Next;
};

typedef unsigned int HashIndex;
typedef struct StrSepHashTable* SepHashTable;
struct StrSepHashTable {
	unsigned int TableSize;
	List * Lists;
};
HashIndex Hash(int key, unsigned int TableSize);
SepHashTable CreateSepHashTable(unsigned int TableSize);
void SepHashInsert(SepHashTable H, int key);
void SepHashTableDelete(SepHashTable H, int key);
#endif