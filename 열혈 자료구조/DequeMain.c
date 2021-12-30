#include <stdio.h>
#include "Deque.h"

int main(){
	Deque deq;//initialization
	DequeInit(&deq);//by constructor
	
	DQAddFirst(&deq, 3); DQAddFirst(&deq, 2); DQAddFirst(&deq, 3);//insert data front
	DQAddLast(&deq, 4); DQAddLast(&deq, 5); DQAddLast(&deq, 6);//insert data back
	
	while(!DQIsEmpty(&deq))//print all by removing
		printf("%d ", DQRemoveFirst(&deq));
	printf("\n");
	
	DQAddFirst(&deq, 3); DQAddFirst(&deq, 2); DQAddFirst(&deq, 3);
	DQAddLast(&deq, 4); DQAddLast(&deq, 5); DQAddLast(&deq, 6);
	
	while(!DQIsEmpty(&deq))
		printf("%d ", DQRemoveLast(&deq));
	printf("\n");
	
	return 0;
}
