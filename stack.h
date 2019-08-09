#ifndef _ELEMENT_S
#define _ELEMENT_S
typedef int Element;
#endif

/* Stack define start */
#ifndef _STACK_H
#define _STACK_H
typedef struct StackNode * PtrToStackNode;
typedef PtrToStackNode StackPst;
typedef PtrToStackNode Stack;
struct StackNode
{
	StackPst next;
	Element ele;
};

Stack createStack(void);
void stackMakeEmpty(Stack s);
_Bool stackIsEmpty(const Stack s);
void deleteStack(Stack s);
Element stackTop(const Stack s);
StackPst stackPush(Stack s, Element e);
Element stackPop(Stack s);
#endif
/* Stack define end */
