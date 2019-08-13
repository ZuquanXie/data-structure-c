#include<stdio.h>
#include "binarytree.h"
void ListBinaryTree(BinaryTree T, int depth);

int main()
{
	BinaryTree T;

	T = CreateBinaryTree(0);
	BinaryTreeInsertLeft(T, 1);
	BinaryTreeInsertRight(T, 2);
	BinaryTreeInsertLeft(BinaryTreeFind(T, 1), 3);
	BinaryTreeInsertRight(BinaryTreeFind(T, 1), 4);

	ListBinaryTree(T, 0);

	printf("1's parentNode: %i\n", BinaryTreeFindParent(T, 1)->Element);
	printf("4's parentNode: %i\n", BinaryTreeFindParent(T, 4)->Element);

	BinaryTreeEmpty(T);

	return 0;
}

void ListBinaryTree(BinaryTree T, int depth)
{
	int i;

	i = 0;
	while (i++ < depth * 2)
		putchar('-');
	printf("%i\n", T->Element);

	if (T->Left != NULL)
		ListBinaryTree(T->Left, depth + 1);

	if (T->Right != NULL)
		ListBinaryTree(T->Right, depth + 1);
}