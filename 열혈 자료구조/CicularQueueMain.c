#include <stdio.h>
#include "CircularQueue.h"

int main(){
	Queue q;
	QueueInit(&q);//initialization
	
	Enqueue(&q, 1); Enqueue(&q, 2);//insert
	Enqueue(&q, 3); Enqueue(&q, 4);
	Enqueue(&q, 5);
	
	while(!QIsEmpty(&q))//print all by dequeuing
		printf("%d ", Dequeue(&q));
	
	return 0;
}
