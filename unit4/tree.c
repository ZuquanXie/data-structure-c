#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

Tree CreateTree(Element ele)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));

	if (T == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}

	T->Element = ele;
	T->FirstChild = NULL;
	T->NextSibling = NULL;

	return T;
}

PtrToTreeNode TreeFind(Tree T, Element ele)
{
	PtrToTreeNode target, result;

	if (T->Element == ele)
		return T;

	target = T->FirstChild;
	result = NULL;
	while (target != NULL) {
		result = TreeFind(target, ele);
		if (result != NULL)
			break;
		target = target->NextSibling;
	}
	if (result != NULL)
		return result;

	return NULL;
}

PtrToTreeNode TreeFindPrev(Tree T, Element ele)
{
	PtrToTreeNode target, result;

	if (T->FirstChild && T->FirstChild->Element == ele)
	{
		return T;
	}

	if (T->NextSibling && T->NextSibling->Element == ele)
	{
		return T;
	}

	target = T->FirstChild;
	result = NULL;
	while (target != NULL)
	{
		if (target->NextSibling && target->NextSibling->Element == ele)
		{
			result = target;
			break;
		}
		result = TreeFindPrev(target, ele);
		if (result != NULL)
			break;
		target = target->NextSibling;
	}

	return result;
}

void TreeEmpty(Tree T)
{
	PtrToTreeNode target, next;

	// free children
	target = T->FirstChild;
	while (target != NULL) {
		next = target->NextSibling;
		TreeEmpty(target);
		target = next;
	}

	printf("Empty %i\n", T->Element);
	free(T);
}

void TreeInsert(Tree T, Element parentEle, Element ele)
{
	PtrToTreeNode parentNode, newNode;

	parentNode = TreeFind(T, parentEle);
	newNode = (PtrToTreeNode)malloc(sizeof(struct TreeNode));

	if (parentNode == NULL) {
		fprintf(stderr, "wrong tree parentEle\n");
		exit(EXIT_FAILURE);
	}

	if (newNode == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}

	newNode->Element = ele;
	newNode->FirstChild = NULL;
	newNode->NextSibling = NULL;

	if (parentNode->FirstChild == NULL)
	{
		parentNode->FirstChild = newNode;
		return;
	}

	newNode->NextSibling = parentNode->FirstChild;
	parentNode->FirstChild = newNode;
}

void TreeDelete(Tree T, Element ele)
{
	PtrToTreeNode target, prev;

	prev = TreeFindPrev(T, ele);

	// prevNode is NULL, so T is root
	if (prev == NULL)
	{
		if (T->Element != ele)
		{
			fprintf(stderr, "wrong delete target\n");
			exit(EXIT_FAILURE);
		}
		TreeEmpty(T);
		return;
	}

	// prevNode is parent
	if (prev->FirstChild && prev->FirstChild->Element == ele) {
		target = prev->FirstChild;
		prev->FirstChild = prev->FirstChild->NextSibling;
		target->NextSibling = NULL;
		TreeEmpty(target);
		return;
	}

	// prevNode is sibling
	target = prev->NextSibling;
	prev->NextSibling = prev->NextSibling->NextSibling;
	target->NextSibling = NULL;
	TreeEmpty(target);
}
