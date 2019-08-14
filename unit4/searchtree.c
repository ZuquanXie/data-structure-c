#include<stdio.h>
#include<stdlib.h>
#include "searchtree.h"

SearchTree CreateSearchTree(Element ele)
{
	SearchTree T;

	T = (SearchTree)malloc(sizeof(struct SearchTreeNode));
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

void SearchTreeEmpty(SearchTree T)
{
	if (T->Left)
		SearchTreeEmpty(T->Left);

	if (T->Right)
		SearchTreeEmpty(T->Right);

	free(T);
}

int SearchTreeIsLeaf(SearchTree T)
{
	if (T->Left == NULL && T->Right == NULL)
		return 1;

	return 0;
}

PtrToSearchTreeNode SearchTreeFind(SearchTree T, Element ele)
{
	PtrToSearchTreeNode target, result;

	target = T;
	result = NULL;
	while (target != NULL)
	{
		if (ele < target->Element)
		{
			if (target->Left == NULL)
				break;
			target = target->Left;
			continue;
		}

		if (ele > target->Element)
		{
			if (target->Right == NULL)
				break;
			target = target->Right;
			continue;
		}

		result = target;
		break;
	}

	return result;
}

PtrToSearchTreeNode SearchTreeFindMin(SearchTree T)
{
	PtrToSearchTreeNode result;

	result = T;
	while (result != NULL)
	{
		if (result->Left == NULL)
			break;
		result = result->Left;
	}

	return result;
}

PtrToSearchTreeNode SearchTreeFindMax(SearchTree T)
{
	PtrToSearchTreeNode result;

	result = T;
	while (result != NULL)
	{
		if (result->Right == NULL)
			break;
		result = result->Right;
	}

	return result;
}

PtrToSearchTreeNode SearchTreeFindParent(SearchTree T, Element ele)
{
	PtrToSearchTreeNode target, result;

	target = T;
	result = NULL;
	while (target != NULL)
	{
		if (ele < target->Element)
		{
			if (target->Left == NULL)
				break;
			if (target->Left->Element == ele)
			{
				result = target;
				break;
			}
			target = target->Left;
			continue;
		}

		if (ele > target->Element)
		{
			if (target->Right == NULL)
				break;
			if (target->Right->Element == ele)
			{
				result = target;
				break;
			}
			target = target->Right;
			continue;
		}

		break;
	}

	return result;
}

void SearchTreeInsert(SearchTree T, Element ele)
{
	PtrToSearchTreeNode target, newNode;

	newNode = (PtrToSearchTreeNode)malloc(sizeof(struct SearchTreeNode));
	if (newNode == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}

	target = T;
	while (target != NULL)
	{
		if (ele < target->Element)
		{
			if (target->Left == NULL)
			{
				target->Left = newNode;
				break;
			}
			target = target->Left;
			continue;
		}
		if (ele > target->Element)
		{
			if (target->Right == NULL)
			{
				target->Right = newNode;
				break;
			}
			target = target->Right;
			continue;
		}
		break;
	}

	// there is a same node in the tree
	if (target == NULL)
	{
		free(newNode);
		return;
	}

	newNode->Element = ele;
	newNode->Left = NULL;
	newNode->Right = NULL;
}

SearchTree SearchTreeDelete(SearchTree T, Element ele)
{
	PtrToSearchTreeNode parent, target, max, mParent;
	enum Position {Left, Right, None};
	enum Position tPosition;

	// find parent, target and target position
	if (T->Element == ele)
	{
		parent = NULL;
		target = T;
		tPosition = None;
	}
	else
	{
		parent = SearchTreeFindParent(T, ele);
		if (parent == NULL)
		{
			fprintf(stderr, "wrong delete target\n");
			exit(EXIT_FAILURE);
		}
		target = SearchTreeFind(parent, ele);
		if (parent->Left == target)
			tPosition = Left;
		else
			tPosition = Right;
	}

	// target is leaf
	if (SearchTreeIsLeaf(target))
	{
		if (tPosition == None)
			T = NULL;
		else if (tPosition == Left)
			parent->Left = NULL;
		else
			parent->Right = NULL;
		free(target);

		return T;
	}

	// target has left child
	if (target->Right == NULL)
	{
		if (tPosition == None)
			T = target->Left;
		else if (tPosition == Left)
			parent->Left = target->Left;
		else
			parent->Right = target->Left;
		free(target);
		return T;
	}

	// target has right child
	if (target->Left == NULL)
	{
		if (tPosition == None)
			T = target->Right;
		else if (tPosition == Left)
			parent->Left = target->Right;
		else
			parent->Right = target->Right;
		free(target);
		return T;
	}

	// target has two child
	max = SearchTreeFindMax(target->Right);
	mParent = SearchTreeFindParent(target, max->Element);
	if (tPosition == None)
		T = max;
	else if (tPosition == Left)
		parent->Left = max;
	else
		parent->Right = max;
	mParent->Right = NULL;
	max->Left = target->Left;
	max->Right = target->Right;
	free(target);
	return T;
}
