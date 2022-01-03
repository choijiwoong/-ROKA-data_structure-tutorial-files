#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph* pg, int nv){
	int i;
	
	pg->adjList=(List*)malloc(sizeof(List)*nv);//allocation. List array
	pg->numV=nv;//set amount of vertex
	pg->numE=0;
	
	for(i=0; i<nv; i++){
		ListInit(&(pg->adjList[i]));//initialization foreach list as much as numV
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);//set list's order for convenience of printing. just it.
	}
}

void GraphDestroy(ALGraph* pg){
	if(pg->adjList!=NULL)
		free(pg->adjList);//array deallocation. not list.
}

void AddEdge(ALGraph* pg, int fromV, int toV){//undirected graph
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;
}

void ShowGraphEdgeInfo(ALGraph* pg){
	int i, vx;
	
	for(i=0; i<pg->numV; i++){//foreach vertex
		printf("Edge that is connedted with %c: ", i+65);
		
		if(LFirst(&(pg->adjList[i]), &vx)){//access first element of list that is in adjList[0]
			printf("%c ", vx+65);
			
			while(LNext(&(pg->adjList[i]), &vx))//access best element of list.
				printf("%c ", vx+65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2){//for clean print
	if(data1<data2)
		return 0;
	else
		return 1;
}
