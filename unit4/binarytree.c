#include<stdio.h>
#include<stdlib.h>
#include "binarytree.h"

BinaryTree CreateBinaryTree(Element ele)
{
	BinaryTree T;

	T = (BinaryTree)malloc(sizeof(struct BinaryTreeNode));
	if (T == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}

	T->Element = ele;
	T->Left = NULL;
	T->Right = NULL;

	return T;
}

PtrToBinaryTreeNode BinaryTreeFind(BinaryTree T, Element ele)
{
	PtrToBinaryTreeNode result;

	if (T->Element == ele)
		return T;

	if (T->Left)
	{
		result = BinaryTreeFind(T->Left, ele);
		if (result != NULL)
			return result;
	}

	if (T->Right)
	{
		result = BinaryTreeFind(T->Right, ele);
		if (result != NULL)
			return result;
	}

	return NULL;
}

PtrToBinaryTreeNode BinaryTreeFindParent(BinaryTree T, Element ele)
{
	PtrToBinaryTreeNode result;

	result = NULL;

	if (T->Left != NULL)
	{
		if (T->Left->Element == ele)
			return T;
		result = BinaryTreeFindParent(T->Left, ele);
		if (result != NULL)
			return result;
	}

	if (T->Right != NULL)
	{
		if (T->Right->Element == ele)
			return T;
		result = BinaryTreeFindParent(T->Right, ele);
	}

	return result;
}

void BinaryTreeEmpty(BinaryTree T)
{
	if (T->Left)
		BinaryTreeEmpty(T->Left);

	if (T->Right)
		BinaryTreeEmpty(T->Right);

	free(T);
}

void BinaryTreeInsertLeft(BinaryTree T, Element ele)
{
	PtrToBinaryTreeNode Left;

	Left = (PtrToBinaryTreeNode)malloc(sizeof(struct BinaryTreeNode));
	if (Left == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}

	if (T->Left != NULL) {
		fprintf(stderr, "wrong insert position\n");
		exit(EXIT_FAILURE);
	}

	Left->Left = NULL;
	Left->Right = NULL;
	Left->Element = ele;
	T->Left = Left;
}

void BinaryTreeInsertRight(BinaryTree T, Element ele)
{
	PtrToBinaryTreeNode Right;

	Right = (PtrToBinaryTreeNode)malloc(sizeof(struct BinaryTreeNode));
	if (Right == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}

	if (T->Right != NULL) {
		fprintf(stderr, "wrong insert position\n");
		exit(EXIT_FAILURE);
	}

	Right->Left = NULL;
	Right->Right = NULL;
	Right->Element = ele;
	T->Right = Right;
}
