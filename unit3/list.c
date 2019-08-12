#include<stdio.h>
#include<stdlib.h>
#include "list.h"

List createList()
{
	List list = (List) malloc(sizeof(struct ListNode));

	if (list == NULL)
		fprintf(stderr, "Out of space!\n"), exit(1);

	return list;
}

_Bool listIsEmpty(const List list)
{
	return list->next == NULL;
}

ListPst listAdd(List list, const Element ele)
{
	PtrToListNode newNode = (PtrToListNode) malloc(sizeof(struct ListNode));
	ListPst p;

	if (newNode == NULL)
		fprintf(stderr, "Out of space!\n"), exit(1);

	newNode->ele = ele;
	p = list;
	while (p->next != NULL)
		p = p->next;
	p->next = newNode;

	return newNode;
}

ListPst listInsert(List list, ListPst pst, const Element ele)
{
	PtrToListNode newNode = (PtrToListNode) malloc(sizeof(struct ListNode));
	ListPst p;

	if (newNode == NULL)
		fprintf(stderr, "Out of space!\n"), exit(1);

	newNode->ele = ele;
	p = list;
	while (p != NULL && p->ele != ele)
		p = p->next;

	if (p == NULL)
		fprintf(stderr, "Insert: wrong position\n"), exit(1);

	newNode->next = p->next;
	p->next = newNode;

	return newNode;
}

void listRemoveNode(List list, Element ele)
{
	ListPst p;

	p = list;
	while (p->ele != ele && p != NULL)
		p = p->next;
	if (p == NULL)
		return;
	free(p);
}

ListPst listFind(const List list, const Element ele)
{
	ListPst p;

	p = list->next;
	while (p != NULL && p->ele != ele)
		p = p->next;

	return p;
}

ListPst listFindPrev(const List list, const Element ele)
{
	ListPst p;

	p = list;
	while (p->next != NULL && p->next->ele == ele)
		p = p->next;

	return p;
}

Element listRetrieval(const ListPst p)
{
	return p->ele;
}

void listMakeEmpty(List list)
{
	ListPst tmpCell;

	tmpCell = list->next;
	while (tmpCell != NULL)
	{
		list->next = tmpCell->next;
		free(tmpCell);
		tmpCell = list->next;
	}
}
