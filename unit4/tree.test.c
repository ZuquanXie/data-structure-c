#include<stdio.h>
#include "tree.h"
void ListTree(Tree T, int deep);

int main()
{
	Tree T;

	T = CreateTree(10);
	TreeInsert(T, 10, 1);
	TreeInsert(T, 1, 2);
	TreeInsert(T, 1, 3);
	TreeInsert(T, 1, 4);
	TreeInsert(T, 1, 5);
	TreeInsert(T, 10, 6);
	TreeInsert(T, 6, 7);
	TreeInsert(T, 6, 8);
	TreeInsert(T, 6, 9);

	ListTree(T, 0);

	printf("6's prevNode: %i\n",  TreeFindPrev(T, 6)->Element);
	printf("8's prevNode: %i\n",  TreeFindPrev(T, 8)->Element);
	printf("10's prevNode is NULL: %i\n",  TreeFindPrev(T, 10) == NULL);

	printf("delete node 6\n");
	TreeDelete(T, 6);
	ListTree(T, 0);

	TreeEmpty(T);

	return 0;
}

void ListTree(Tree T, int depth)
{
	int i;
	PtrToTreeNode target;

	i = 0;
	while (i++ < depth * 2)
		putchar('-');
	printf("%i\n", T->Element);

	target = T->FirstChild;
	while (target != NULL)
	{
		ListTree(target, depth + 1);
		target = target->NextSibling;
	}
}