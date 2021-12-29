#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq){
	pq->front=0;
	pq->rear=0;
}

int QIsEmpty(Queue* pq){
	if(pq->front==pq->rear)//check empty stats by comparing front & rear. (if full state, only F is NULL)
		return TRUE;
	else
		return FALSE;
}

//Concept of CircularQueue. IMPORTANT
int NextPosIdx(int pos){//get next index with range checking.
	if(pos==QUE_LEN-1)//last one space will be used for distinguish full state & empty state. skip last index and return first index
		return 0;//return first index
	else
		return pos+1;
}

void Enqueue(Queue* pq, Data data){
	if(NextPosIdx(pq->rear)==pq->front){
		printf("Queue Memory Error!");
		exit(-1);
	}
	
	pq->rear=NextPostIdx(pq->rear);//set rear by NextPostIdx
	pq->queArr[pq->rear]=data;//add data by using rear.
}

Data QPeek(Queue* pq){
	if(QIsEmpty(pq)){
		printf("Queue Memory Error!");
		exit(-1);
	}
	
	return pq->queArr[NextPosIdx(pq->front)];//front points empty node. so approach first element by using NextPosIdx
	//Front always points empty node for distinguishing empty, full
}
