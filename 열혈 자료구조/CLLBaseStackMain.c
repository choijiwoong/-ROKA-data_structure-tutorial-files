#include <stdio.h>
#include "CLLBaseStack.h"

int main(){
	Stack stack;
	StackInit(&stack);//�ణ virtual overloading������ �� ���µ�... CLinkedList���� ListInit�̱� �ѵ� ���� �̸� ��ġ�� �ߺ������� �߰���..? 
	
	SPush(&stack, 1); SPush(&stack, 2);
	Spush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);
	
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));
		
	return 0;
}
