#include<stdio.h>
#include<stdlib.h>
#include "book.h"
#include "../list.h"

int main()
{
	List list = createList();
	PtrToBook math = createBook("math", 12.5);
	PtrToBook history = createBook("history", 24.5);
	ListPst p;

	listAdd(list, math);
	listAdd(list, history);

	p = list->next;
	while (p != NULL)
	{
		printf("Name: %s  price: %.2f\n", listRetrieval(p)->name, listRetrieval(p)->price);
		p = p->next;
	}

	listMakeEmpty(list);

	return 0;
}
