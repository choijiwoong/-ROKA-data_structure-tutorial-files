#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack){
	pstack->topIndex=-1;//not referring!
}

int SIsEmpty(Stack* pstack){
	if(pstack->topIndex==-1)//check by topIndex location is -1
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data){
	pstack->topIndex++;
	pstack->stackArr[pstack->topIndex]=data;//save data on increased index.
}

Data SPop(Stack* pstack){
	int rIdx;
	
	if(SIsEmpty(pstack)){//no data for pop
		printf("Stack Memory Error!");
		exit(-1);//?
	}
	
	rIdx=pstack->topIndex;//get index for accessing index that will be removed
	pstack->topIndex--;
	
	return pstack->stackArr[rIdx];//we can use it also topIndex-1 without rIdx. but we will ignore basic logic 'we can access in range 0~topIndex' meaningfully..? :d
	//we don't have any disadvantage of that logic.. but keeping that will be good for us...in extention.
}

Data SPeek(Stack* pstack){
	if(SIsEmpty(pstack)){//no data for peek
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];//just return element without removing(modifying topIndex).
}
