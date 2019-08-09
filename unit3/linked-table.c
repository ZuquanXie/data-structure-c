#include<stdio.h>
#include<stdlib.h>
#define BOOK_NAME_LEN 20

struct Book{
	char name[BOOK_NAME_LEN];
	double price;
};

struct BookTableEle{
	struct Book * book;
	struct BookTableEle * prev;
	struct BookTableEle * next;
};

static struct BookTableEle * BookTable;

void setBook(char name[], double * price);

void removeBook(struct BookTableEle * table, char bookname[]);

void addBook(struct BookTableEle ** table);

void cleanBookTable(struct BookTableEle * table);

void showBookTable(const struct BookTableEle * table);

void addBooksFromFile(char filename[], struct BookTableEle ** table);

int main()
{
	addBooksFromFile("linked-table.data", &BookTable);
/*
	int i;

	for (i = 5; i > 0; i--)
	{
		printf("%i books are waitting to be added\n", i);
		addBook(&BookTable); 
		putchar('\n');
	}

	putchar('\n');
	showBookTable(BookTable);
	putchar('\n');
*/
	putchar('\n');
	showBookTable(BookTable);
	putchar('\n');

	cleanBookTable(BookTable);

	return 0;
}

void setBook(char name[], double * price)
{
	printf("Please enter name:\n");
	scanf("%s", name);
	while (getchar() != '\n')
		continue;

	printf("Please enter price:\n");
	scanf("%lf", price);
	while (getchar() != '\n')
		continue;
}

void addBook(struct BookTableEle ** table)
{
	struct Book * newBook = (struct Book *) malloc(sizeof(struct Book));
	struct BookTableEle * newBookEle = (struct BookTableEle *) malloc(sizeof(struct BookTableEle));
	struct BookTableEle * lastEle;

	setBook(newBook->name, &newBook->price);
	newBookEle->book = newBook;

	if (*table == NULL)
	{
		*table = newBookEle;
		return;
	}

	lastEle = *table;
	while(lastEle->next != NULL)
		lastEle = lastEle->next;
	lastEle->next = newBookEle;
	newBookEle->prev = lastEle;
}

void showBookTable(const struct BookTableEle * table)
{
	int i;
	const struct BookTableEle * next;

	i = 0;
	next = table;
	printf("%-20s  %-10s\n", "name", "price");
	for (int j = 0; j < 32; j++)
		putchar('-');
	putchar('\n');
	while (next != NULL)
	{
		printf("%-20s  %-10.1lf\n", next->book->name, next->book->price);
		next = next->next;
		i++;
	}
	for (int j = 0; j < 32; j++)
		putchar('-');
	putchar('\n');
	printf("count: %i\n", i);

}

void cleanBookTable(struct BookTableEle * table)
{
	int i;
	struct BookTableEle * next;
	struct BookTableEle * current;

	i = 0;
	next = table;
	while (next != NULL)
	{
		current = next;
		next = next->next;
		free(current->book);
		free(current);
		i++;
	}
	printf("%i books have been removed!\n", i);

}

void addBooksFromFile(char filename[], struct BookTableEle ** table)
{
	FILE * file;
	int countEleAdded = 0;
	struct BookTableEle * endEle = NULL;

	if((file = fopen(filename, "r")) == NULL)
	{
		printf("Can't open file %s\n", filename);
		return;
	}

	/* find the end element of table */
	if (*table != NULL)
	{
		endEle = *table;
		while (endEle->next != NULL)
			endEle = endEle->next;
	}

	char ch;
	int chCount;
	int priceStrLen = 10;
	char nameStr[BOOK_NAME_LEN + 1], priceStr[priceStrLen + 1];
	while(ch != EOF)
	{
		struct BookTableEle * newEle;

		/* remove empty line */
		do
		{
			ch = getc(file);
		} while (ch == '\n' || ch == ' ');
		if (ch == EOF)
			break;

		/* get name */
		chCount = 0;
		while (ch != '\n' && ch != ' ' && ch != EOF)
		{
			if (chCount < BOOK_NAME_LEN)
				nameStr[chCount++] = ch;
			ch = getc(file);
		}
		// create new table element
		newEle = (struct BookTableEle *) malloc(sizeof(struct BookTableEle));
		newEle->book = (struct Book *) malloc(sizeof(struct Book));
		if (endEle == NULL)
		{
			*table = endEle = newEle;
		} else
		{
			endEle->next = newEle;
			newEle->prev = endEle;
			endEle = newEle;
		}
		for (int i = 0; i < chCount; i++)
			newEle->book->name[i] = nameStr[i];
		newEle->book->name[chCount] = '\0';
		countEleAdded++;

		if (ch == EOF)
			break;
		if (ch == '\n')
			continue;
		/* get price */
		chCount = 0;
		while (ch != '\n' && ch != EOF)
		{	
			if (chCount < priceStrLen)
				priceStr[chCount++] = ch;
			ch = getc(file);
		}
		priceStr[chCount] = '\0';
		newEle->book->price = atof(priceStr);
	}
	printf("%i records were added from file %s\n", countEleAdded, filename);
}
