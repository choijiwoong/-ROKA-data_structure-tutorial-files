#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq){
	pq->front=NULL;
	pq->rear=NULL;
}

int QIsEmpty(Queue* pq){
	if(pq->front==NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data
	newNode->next=NULL;
	
	if(QIsEmpty(pq)){//is empty state,
		pq->front=newNode;//front points newNode too.
		pq->rear=newNode;//rear setting
	} else{
		pq->rear->next=newNode;//initial node's next to newNode
		pq->rear=newNode;//rear setting
	}
}

Data Dequeue(Queue* pq){
	Node* delNode;
	Data retData;
	
	if(QIsEmpty(pq)){//exception handling
		printf("Queue Memory Error!");
		exit(-1);
	}
	
	delNode=pq->front;//for free
	retData=delNode->data;//for return
	pq->front=pq->front->next;//connect
	
	free(delNode);
	return retData;
}

Data QPeek(Queue* pq){
	if(QIsEmpty(pq)){//exception handling(also)
		printf("Queue Memory Error!");
		exit(-1);
	}
	
	return pq->front->data;//get data without removing
}
