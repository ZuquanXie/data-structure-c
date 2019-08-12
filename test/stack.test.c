#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "book.h"
#include "../unit3/stack.h"

void showBooks(Stack stack);

int main()
{
	Stack stack;
	Element popEle;
	BookP history, math;

	stack = createStack();
	history = createBook("History", 12.5);
	math = createBook("Math", 10);
	
	printf("push history\n");
	stackPush(stack, history);
	printf("push math\n");
	stackPush(stack, math);
	printf("result:\n");
	showBooks(stack);

	printf("\ntop\n");
	printf("%s  %.1f\n", (stackTop(stack))->name, (stackTop(stack))->price);

	printf("\npop\n");
	popEle = stackPop(stack);
	if (popEle != NULL)
		printf("%s  %.1f\n", popEle->name, popEle->price);
	else
		printf("pop NULL\n");

	printf("deleteStack\n");
	deleteStack(stack);
	free(history);
	free(math);

	return 0;
}

void showBooks(Stack stack)
{
	StackPst p;

	p = stack->next;
	while (p != NULL)
	{
		printf("%s  %.1f\n", p->ele->name, p->ele->price);
		p = p->next;
	}
}
