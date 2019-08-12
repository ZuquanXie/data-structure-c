#include<stdlib.h>
#include "tree.h"

Tree CreateTree(void)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));

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
		result = TreeFind(T, ele);
		target = target->NextSibling;
		if (result != NULL)
			break;
	}
	if (result != NULL)
		return result;

	return TreeFind(T->NextSibling, ele);
}

void TreeEmpty(Tree T)
{
	PtrToTreeNode target;

	// free children
	target = T->FirstChild;
	while (target != NULL) {
		TreeEmpty(target);
		target = target->NextSibling;
	}
	
	// free sibling
	if (T->NextSibling != NULL) {
		TreeEmpty(T->NextSibling);
	}

	free(T);
}
