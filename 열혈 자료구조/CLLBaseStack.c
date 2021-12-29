#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "CLLBaseStack.h"

void StackInit(Stack* pstack){
	pstack->plist=(List*)malloc(sizeof(List));
	ListInit(pstack->plist);//use CLinkedList.h
}

int SIsEmpty(Stack* pstack){
	if(LCount(pstack->plist)==0)//check plist member(CLinkedList) by CLInkedList.h's function 
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data){
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack* pstack){
	Data data;
	LFirst(pstack->plist, &data);//get data to data(set cur to first also)
	LRemove(pstack->plist);//remove cur
	
	return data;
}

Data SPeek(Stack* pstack){
	Data data;
	LFirst(pstack->plist, &data);
	
	return data;//just get data without removing
}
