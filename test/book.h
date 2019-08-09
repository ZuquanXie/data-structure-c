#define _ELEMENT_S
#define BOOK_NAME_LEN 20
typedef struct Book * PtrToBook;
typedef PtrToBook BookP;
typedef PtrToBook Element;
struct Book
{
	char name[BOOK_NAME_LEN + 1];
	double price;
};
PtrToBook createBook(char name[], double price);
void removeBook(PtrToBook);
