#include<stdio.h>
#include<stdlib.h>
#include "searchtree.h"
void ListSearchTree(SearchTree T, int depth);

int main()
{
	SearchTree T = CreateSearchTree(3);
	SearchTreeInsert(T, 2);
	SearchTreeInsert(T, 1);
	SearchTreeInsert(T, 6);
	SearchTreeInsert(T, 9);
	SearchTreeInsert(T, 7);
	SearchTreeInsert(T, 10);
	SearchTreeInsert(T, 4);
	SearchTreeInsert(T, 5);

	ListSearchTree(T, 0);

	T = SearchTreeDelete(T, 9);
	ListSearchTree(T, 0);

	SearchTreeEmpty(T);

	return 0;
}

void ListSearchTree(SearchTree T, int depth)
{
	int i;

	i = 0;
	while (i++ < depth * 2)
		putchar('-');
	printf("%i\n", T->Element);

	if (T->Left != NULL)
		ListSearchTree(T->Left, depth + 1);

	if (T->Right != NULL)
		ListSearchTree(T->Right, depth + 1);
}
