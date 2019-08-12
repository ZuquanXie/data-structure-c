#include<stdio.h>
#include<string.h>
#include "book.h"
#include "../unit3/queue.h"

int main()
{
	Queue queue;
	BookP math, history;

	queue = createQueue();
	math = createBook("Math", 12.5);
	history = createBook("History", 10.5);

	// enqueue
	printf("math enqueue\n");
	enqueue(queue, math);
	printf("history enqueue\n");
	enqueue(queue, history);

	// queue count
	printf("queue count: %i\n", queue->count);

	// dequeue
	printf("dequeue1: %s\n", dequeue(queue)->name);
	printf("count: %i\n", queue->count);
	printf("dequeue2: %s\n", dequeue(queue)->name);
	printf("count: %i\n", queue->count);

	return 0;
}
