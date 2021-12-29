#include <stdio.h>
#include "CLLBaseStack.h"

int main(){
	Stack stack;
	StackInit(&stack);//약간 virtual overloading느낌도 좀 나는데... CLinkedList에는 ListInit이긴 한데 만약 이름 겹치면 중복오류가 뜨겠지..? 
	
	SPush(&stack, 1); SPush(&stack, 2);
	Spush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);
	
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));
		
	return 0;
}
