#include <stdio.h>
#include "ListBasedStack.h"

int main(){
	Stack stack;
	StackInit(&stack);//initialization
	
	SPush(&stack, 1); SPush(&stack, 2);//Insert data
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);
	
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));
	
	return 0;
}
