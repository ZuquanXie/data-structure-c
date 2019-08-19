#ifndef _ELEMENT_H
#define _ELEMENT_H
typedef int Element;
#endif

#ifndef _BINARYHEAP_H
#define _BINARYHEAP_H
typedef struct BinaryHeapStruct* BinaryHeap;
BinaryHeap InitializeBinaryHeap(unsigned int Capacity);
void BinaryHeapInsert(BinaryHeap H, Element ele);
Element BinaryHeapDeleteMin(BinaryHeap H);

struct BinaryHeapStruct {
	unsigned int Capacity;
	unsigned int Size;
	Element* Elements;
};
#endif