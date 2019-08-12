#ifndef _ELEMENT_H
#define _ELEMENT_H
typedef int Element;
#endif

#ifndef _TREE_H
#define _TREE_H
typedef struct TreeNode* PtrToTreeNode;
typedef PtrToTreeNode Tree;
struct TreeNode {
	Element Element;
	PtrToTreeNode FirstChild;
	PtrToTreeNode NextSibling;
};
Tree CreateTree(Element ele);
PtrToTreeNode TreeFind(Tree T, Element ele);
PtrToTreeNode TreeFindPrev(Tree T, Element ele);
void TreeEmpty(Tree T);
void TreeInsert(Tree T, Element parentEle, Element ele);
void TreeDelete(Tree T, Element ele);
#endif
