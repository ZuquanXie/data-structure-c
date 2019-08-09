#include<stdlib.h>
#include<string.h>
#include "book.h"

PtrToBook createBook(char name[], double price)
{
	PtrToBook book = (PtrToBook) malloc(sizeof(struct Book));

	strcpy(book->name, name);
	book->price = price;

	return book;
}

void removeBook(PtrToBook book)
{
	free(book);
}
