#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

BTree CreateBTree()
{
	Branch B;

	B = (Branch)malloc(sizeof(struct BranchNode));
	if (B == NULL)
	{
		fprintf(stderr, "out of memory");
		exit(EXIT_FAILURE);
	}

	B->Bounds = NULL;
	B->Branches = NULL;
	B->Leaves = NULL;
	B->ChildCount = 0;

	return B;
}

BTree BTreeInsert(BTree T, Element ele)
{
	LeafNode newNode;

	if (T->Bounds == NULL)
	{
		if (T->Leaves == NULL)
		{
			T->Leaves = (Leaves)malloc(sizeof(Leaf) * LEVEL);
		}
		else if (T->Leaves)
		{

		}
	}

	return T;
}