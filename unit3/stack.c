#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack createStack(void)
{
	Stack stack = (Stack) malloc(sizeof(struct StackNode));

	if (stack == NULL)
	{
		fprintf(stderr, "Out of space!\n"), exit(1);
	}
	stack->next = NULL;

	return stack;
}

void stackMakeEmpty(Stack stack)
{
	if (stack == NULL)
		fprintf(stderr, "Not a stack\n"), exit(1);
	while (!stackIsEmpty(stack))
		stackPop(stack);
}

_Bool stackIsEmpty(const Stack stack)
{
	return stack->next == NULL;
}

void deleteStack(Stack stack)
{
	if (stack == NULL)
		fprintf(stderr, "Delete: not a stack\n"), exit(1);
	stackMakeEmpty(stack);
	free(stack);
}

Element stackTop(const Stack stack)
{
	if (stackIsEmpty(stack))
		fprintf(stderr, "Top: null stack!\n"), exit(1);
	return stack->next->ele;
}

StackPst stackPush(Stack stack, Element ele)
{
	PtrToStackNode newNode = (StackPst) malloc(sizeof(struct StackNode));

	newNode->next = stack->next;
	stack->next = newNode;
	newNode->ele = ele;

	return newNode;
}

Element stackPop(Stack stack)
{
	StackPst tempCell;
	Element ele;

	if (stackIsEmpty(stack))
		fprintf(stderr, "Pop: null stack\n"), exit(1);
	tempCell = stack->next;
	ele = tempCell->ele;
	stack->next = tempCell->next;
	free(tempCell);
	return ele;
}
