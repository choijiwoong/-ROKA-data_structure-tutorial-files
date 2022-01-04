#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphBFS.h"
#include "DLinkedList.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph* pg, int nv){
	int i;
	
	pg->adjList=(List*)malloc(sizeof(List)*nv);
	pg->numV=nv;
	pg->numE=0;
	
	for(i=0; i<nv; i++){
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
	
	pg->visitInfo=(int*)malloc(sizeof(int)*pg->numV);
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);//same with ALGraphDFS.h
}

void GraphDestroy(ALGraph* pg){
	if(pg->adjList!=NULL)
		free(pg->adjList);
		
	if(pg->visitInfo!=NULL)
		free(pg->visitInfo);//same with ALGraphDFS.h
}

void AddEdge(ALGraph* pg, int fromV, int toV){
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;//same with ALGraphDFS.h
}

void ShowGraphEdgeInfo(ALGraph* pg){
	int i, vx;
	
	for(i=0; i<pg->numV; i++){
		printf("Edge that is connedted with %c: ", i+65);
		
		if(LFirst(&(pg->adjList[i]), &vx)){
			printf("%c ", vx+65);
			
			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx+65);
		}
		printf("\n");
	}//same with ALGraphDFS.h
}

int WhoIsPrecede(int data1, int data2){
	if(data1<data2)
		return 0;
	else
		return 1;//same with ALGraphDFS.h
}

int VisitVertex(ALGraph* pg, int visitV){
	if(pg->visitInfo[visitV]==0){
		pg->visitInfo[visitV]=1;
		printf("%c ", visitV+65);
		return TRUE;
	}
	return FALSE;//same with ALGraphDFS.h
}

void BFShowGraphVertex(ALGraph* pg, int startV){//Breadth First Search의 핵심은 Queue로, 가능한 vertex를 enqueue후 여러항목있다면 Dequeue하여 나오는거 먼저 연락하며 그 항목들을 다시 Enqueue하는 방식으로 접근한다. 
	Queue queue;
	itn visitV=startV;
	int nextV;
	
	QueueInit(&queue);
	VisitVertex(pg, visitV);
	
	while(LFirst(&(pg->adjList[visitV]), &nextV)==TRUE){
		if(VisitVertex(pg, nextV)==TRUE)//whitout if, else, break. because it's BFS that saves all possible vertex.
			Enqueue(&queue, nextV);
		while(LNext(&(pg->adjList[visitV]), &nextV)==TRUE){
			if(VisitVertex(pg, nextV)==TRUE)
				Enqueue(&queue, nextV);
		}
		
		if(QIsEmpty(&queue)==TRUE)
			break;
		else
			visitV=Dequeue(&queue);//Last element of queue is dequeued for giving change for contect. and then, truly done.
	}
	
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}
