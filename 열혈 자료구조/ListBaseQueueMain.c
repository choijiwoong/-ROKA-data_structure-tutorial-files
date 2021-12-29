#include <stdio.h>
#include "ListBaseQueue.h"

int main(){
	Queue q;
	QueueInit(&q);//initialziation by constructor of Qyeye
	
	Enqueue(&q, 1); Enqueue(&q, 2);//insert
	Enqueue(&q, 3); Enqueue(&q, 4);
	Enqueue(&q, 5);
	
	while(!QIsEmpty(&q))//print all by dequeuing
		printf("%d ", Dequeue(&q));
	
	return 0;
}
