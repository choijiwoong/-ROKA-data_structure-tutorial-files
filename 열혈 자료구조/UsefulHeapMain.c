#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2){//user design!
	return ch2-ch1;
	//return ch1-ch2;//reversely
}

int main(){
	Heap heap;
	HeapInit(&heap, DataPriorityComp);//initialization with designed comparator
	
	HInsert(&heap, 'A');//data insert
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));
	
	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));
	
	while(!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));//delete with print
	
	return 0;
}
