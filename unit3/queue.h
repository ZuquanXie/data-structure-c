#ifndef _ELEMENT_S
#define _ELEMENT_S
typedef int Element;
#endif
#ifndef _QUEUE_H
#define _QUEUE_H
typedef struct QueueNode * PtrToQueueNode;
typedef PtrToQueueNode QueuePst;
typedef struct Queue * Queue;
struct QueueNode
{
	QueuePst next;
	Element ele;
};
struct Queue
{
	QueuePst front;
	QueuePst rear;
	int count;
};
Queue createQueue(void);
_Bool queueIsEmpty(const Queue q);
void queueMakeEmpty(Queue q);
QueuePst enqueue(Queue q, Element ele);
Element dequeue(Queue q);
#endif
