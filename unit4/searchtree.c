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

	if (T->Element == ele)
	{
		parent = NULL;
		target = T;
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
	}

	if (target->Left == NULL)
	{
		if (parent == NULL)
			T = target->Right;
		else if (parent->Left == target)
			parent->Left = target->Right;
		else
			parent->Right = target->Right;
		free(target);
		return T;
	}

	max = SearchTreeFindMax(target->Left);
	mParent = SearchTreeFindParent(target, max->Element);
	if (parent == NULL)
		T = max;
	else if (parent->Left == target)
		parent->Left = max;
	else
		parent->Right = max;

	if (max != target->Left)
		max->Left = target->Left;
	else
		mParent->Right = NULL;
	max->Right = target->Right;
	free(target);

	return T;
}
