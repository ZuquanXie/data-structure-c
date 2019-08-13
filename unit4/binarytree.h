#ifndef _ELEMENT_H
#define _ELEMENT_H
typedef int Element;
#endif

#ifndef _BINARYTREE_H
#define _BINARYTREE_H
typedef struct BinaryTreeNode * PtrToBinaryTreeNode;
typedef PtrToBinaryTreeNode BinaryTree;
struct BinaryTreeNode {
	Element Element;
	PtrToBinaryTreeNode Left;
	PtrToBinaryTreeNode Right;
};
BinaryTree CreateBinaryTree(Element ele);
PtrToBinaryTreeNode BinaryTreeFind(BinaryTree T, Element ele);
PtrToBinaryTreeNode BinaryTreeFindParent(BinaryTree T, Element ele);
void BinaryTreeEmpty(BinaryTree T);
void BinaryTreeInsertLeft(BinaryTree T, Element ele);
void BinaryTreeInsertRight(BinaryTree T, Element ele);
#endif