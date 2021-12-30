#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq){//initialization
	pdeq->head=NULL;
	pdeq->tail=NULL;
}

int DQIsEmpty(Deque* pdeq){
	if(pdeq->head==NULL)//judge empty state by head
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;//new node setting
	
	newNode->next=pdeq->head;//new's next->head
	
	if(DQIsEmpty(pdeq))//additional work by empty state
		pdeq->tail=newNode;//tail setting
	else
		pdeq->head->prev=newNode;//head element's prev->new
		
	newNode->prev=NULL;//new's prev->NULL(because it's head element)
	pdeq->head=newNode;//head setting
}

void DQAddLast(Deque* pdeq, Data data){//simillar with DQAddFirst. head changes to tail with reversed direction
	Node8 newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	
	newNode->prev=pdeq->tail;//new's prev->tail
	
	if(DQIsEmpty(pdeq))//additional work by empty state
		pdeq->head=newNode;
	else
		pdeq->tail->next=newNode;//tail element's next->new
	
	newNode->next=NULL;//new's next->NULL(because it's tail element)
	pdeq->tail=newNode;//tail setting
}

Data DQRemoveFirst(Deque* pdeq){
	Node* rnode=pdeq->head;//for free
	Data rdata;//for return
	
	if(DQIsEmpty(pdeq)){//exception handling
		printf("Deque Memory Error!");
		exit(-1);
	}
	
	rdata=pdeq->head->data;//get data for return

	pdeq->head=pdeq->head->next;//shift for removing
	free(rnode);//deallocation
	
	if(pdeq->head==NULL)//Now, if it's empty
		pdeq->tail=NULL;//tail set NULL
	else
		pdeq->head->prev=NULL;//new's prev setting(because it's new head element)
	
	return rdata;
}

Data DQRemoveLast(Deque* pdeq){//simillar with DQRemoveFirst too
	Node* rnode=pdeq->tail;//for free
	Data rdata;//for return
	
	if(DQIsEmpty(pdeq)){//exception handling
		printf("Deque Memory Error!");
		exit(-1);
	}
	
	rdata=pdeq->tail->data;//get data for return
	
	pdeq->tail=pdeq->tail->prev;//shift for removing
	free(rnode);//deallocation
	
	if(pdeq->tail==NULL)//Now, it's empty
		pdeq->head=NULL;//head setting
	else
		pdeq->tail->next=NULL;//tail's next setting(new element's next)
		
	return rdata;
}

Data DQGetFirst(Deque* pdeq){
	if(DQIsEmpty(pdeq)){//exception handling
		printf("Deque Memory Error!");
		exit(-1);
	}
	
	return pdeq->head->data;//without removing
}

Data DQGetLast(Deque* pdeq){
	if(DQIsEmpty(pdeq)){//Exception handling
		printf("Deque Memory Error!");
		exit(-1);
	}
	
	return pdeq->tail->data;//without removing
}
