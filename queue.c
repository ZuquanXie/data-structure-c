#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

Queue createQueue()
{
	Queue queue = (Queue) malloc(sizeof(struct Queue));

	if (queue == NULL)
		fprintf(stderr, "Out of space!\n"), exit(1);

	queue->count = 0;
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}

_Bool queueIsEmpty(Queue queue)
{
	return queue->front == NULL;
}

void queueMakeEmpty(Queue queue)
{
	while (!queueIsEmpty(queue))
		dequeue(queue);
}

QueuePst enqueue(Queue queue, Element ele)
{
	QueuePst newNode = (QueuePst) malloc(sizeof(struct QueueNode));

	newNode->ele = ele;
	queue->count++;
	if (queueIsEmpty(queue))
	{
		queue->front = newNode;
		queue->rear = newNode;
		return newNode;
	}
	queue->rear->next = newNode;
	queue->rear = newNode;

	return newNode;
}

Element dequeue(Queue queue)
{
	QueuePst p;
	Element ele;

	if (queueIsEmpty(queue))
		fprintf(stderr, "Dequeue: null queue\n"), exit(1);

	queue->count--;
	p = queue->front;
	ele = p->ele;
	if (p == queue->rear)
	{
		queue->front = NULL;
		queue->rear = NULL;
	} else
	{
		queue->front = p->next;
	}
	free(p);

	return ele;
}
