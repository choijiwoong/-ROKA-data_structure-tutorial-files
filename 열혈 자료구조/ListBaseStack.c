#include <stdio.h>
#include <stdlib.h>
#include "ListBasedStack.h"

void StackInit(Stack* pstack){
	pstack->head=NULL;//Empty. floor of stack now
}
//행복하네 
int SIsEmpty(Stack* pstack){
	if(pstack->head==NULL)//Is head NULL?
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data){
	Node* newNode=(Node*)malloc(sizeof(Node));//Initialization of new Node
	newNode->data=data;
	
	newNode->next=pstack->head;//connect by head
	pstack->head=newNode;
}

Data SPop(stack* pstack){
	Data rdata;//for return
	Node* rnode;//for free
	
	if(SIsEmpty(pstack)){
		printf("Stack Memory Error!");
		exit(-1);//file IO auto save, finish process and pass permission to operation system.
		//Commonly, exit(0) is well done, exit(1) is done with error MSG
	}
	
	rdata=pstack->head->data;//save
	rnode=pstack->head;
	
	pstack->head=pstack->head->next;//cover
	free(rnode);//deallocation
	
	return rdata;
}

Data SPeek(Stack* pstack){
	if(SIsEmpty(pstack)){
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->head->data;//return data without removing
}
