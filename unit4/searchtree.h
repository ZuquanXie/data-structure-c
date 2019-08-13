#ifndef _ELEMENT_H
#define _ELEMENT_H
typedef int Element;
#endif

#ifndef _SEARCHTREE_H
#define _SEARCHTREE_H
typedef struct SearchTreeNode* PtrToSearchTreeNode;
typedef PtrToSearchTreeNode SearchTree;
struct SearchTreeNode {
	Element Element;
	PtrToSearchTreeNode Left;
	PtrToSearchTreeNode Right;
};
SearchTree CreateSearchTree(Element ele);
void SearchTreeEmpty(SearchTree T);
PtrToSearchTreeNode SearchTreeFind(SearchTree T, Element ele);
PtrToSearchTreeNode SearchTreeFindMin(SearchTree T);
PtrToSearchTreeNode SearchTreeFindMax(SearchTree T);
PtrToSearchTreeNode SearchTreeFindParent(SearchTree T, Element ele);
void SearchTreeInsert(SearchTree T, Element ele);
SearchTree SearchTreeDelete(SearchTree T, Element ele);
#endif