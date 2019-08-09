#define _ELEMENT_S
typedef char Element;
#include<stdio.h>
#include<stdlib.h>
#include "../stack.h"
#include "../queue.h"
#include "utils.h"
#define sIsE(s) stackIsEmpty(s)
#define top(s) stackTop(s)
#define pop(s) stackPop(s)
#define push(s, e) stackPush(s, e)
#define qIsE(q) queueIsEmpty(q)
#define MAX_EXPRESSION_LEN 100

void createPostfix(char infix[], char postfix[])
{
	// postfix
	char * pPostfix = &postfix[0];
	// numbers
	Queue n = createQueue();
	// operators
	Stack o = createStack();
	// character
	Element c;
	int i;

	i = -1;
	while (infix[++i] != '\0' || i > MAX_EXPRESSION_LEN)
	{
		if (infix[i] >= 'a' && infix[i] <= 'z')
		{
			enqueue(n, infix[i]);
			continue;
		}

		if (infix[i] == '+' || infix[i] == '-')
		{
			if (sIsE(o) || (top(o) != '*' && top(o) != '/'))
			{
				push(o, infix[i]);
				continue;
			}
			while (!qIsE(n))
			{
				*pPostfix = dequeue(n);
				pPostfix++;
			}
			while (!sIsE(o) && top(o) != '(')
			{
				*pPostfix = pop(o);
				pPostfix++;
			}
			push(o, infix[i]);
			continue;
		}

		if (infix[i] == '*' || infix[i] == '/' || infix[i] == '(')
		{
			push(o, infix[i]);
			continue;
		}

		if (infix[i] == ')')
		{
			while (!qIsE(n))
			{
				*pPostfix = dequeue(n);
				pPostfix++;
			}
			while (!sIsE(o))
			{
				if (top(o) == '(')
				{
					pop(o);
					break;
				}
				*pPostfix = pop(o);
				pPostfix++;
			}
			continue;
		}
	}
	while (!qIsE(n))
	{
		*pPostfix = dequeue(n);
		pPostfix++;
	}
	while (!sIsE(o))
	{
		*pPostfix = pop(o);
		pPostfix++;
	}
	*pPostfix = '\0';
	free(n);
	free(o);
}

int main()
{
	char infix[MAX_EXPRESSION_LEN + 1];
	char postfix[MAX_EXPRESSION_LEN + 1];

	do
	{
		printf("Please enter a infix expression:\n");
		getstr(infix, MAX_EXPRESSION_LEN + 1);
		printf("infix expression: %s\n", infix);
		createPostfix(infix, postfix);
		printf("postfix expression: %s\n", postfix);
		printf("\nPress enter to continue, other to exit\n");
	} while (getchar() == '\n');

	return 0;
}
