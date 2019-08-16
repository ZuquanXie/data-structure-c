#ifndef _ELEMENT_H
#define _ELEMENT_H
typedef int Element;
#endif

#ifndef _BTREE_H
#define _BTREE_H
#define LEVEL 3
typedef struct LeafNodeStr* LeafNode;
typedef LeafNode* Leaf;
typedef Leaf* Leaves;
typedef int* Bound;
typedef struct BranchNode* Branch;
typedef Branch BTree;
struct LeafNodeStr {
	Element Element;
};
struct BranchNode {
	Bound Bounds;
	Branch Branches;
	Leaves Leaves;
	int ChildCount;
};
BTree CreateBTree();
BTree BTreeInsert(BTree T, Element ele);
#endif