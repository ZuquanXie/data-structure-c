#ifndef _ELEMENT_S
#define _ELEMENT_S
typedef int Element;
#endif

#ifndef _LIST_H
#define _LIST_H
typedef struct ListNode * PtrToListNode;
typedef PtrToListNode List;
typedef PtrToListNode ListPst;
struct ListNode
{
	ListPst next;
	Element ele;
};
List createList(void);
void listMakeEmpty(List list);
_Bool listIsEmpty(const List list);
ListPst listAdd(List list, const Element ele);
ListPst listInsert(List list, ListPst pst, const Element ele);
void listRemoveNode(List list, Element ele);
ListPst listFind(const List list, const Element ele);
ListPst listFindPrev(const List list, const Element ele);
Element listRetrieval(const ListPst p);
#endif
