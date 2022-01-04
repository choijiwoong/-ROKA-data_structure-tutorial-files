#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph* pg, int nv){
	int i;
	
	pg->adjList=(List*)malloc(sizeof(List)*nv);
	pg->numV=nv;
	pg->numE=0;
	
	for(i=0; i<nv; i++){
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}//same with ALGraph.h
	
	pg->visitInfo=(int*)malloc(sizeof(int)*pg->numV);//for saving visit information to vertexes.
	//(allocation as much as vertex for check visit check for all vertex)
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);//set ZERO
}

void GraphDestroy(ALGraph* pg){
	if(pg->adjList!=NULL)
		free(pg->adjList);//same with ALGraph.h
		
	if(pg->visitInfo!=NULL)
		free(pg->visitInfo);//deallocation visitInfo too.
}

void AddEdge(ALGraph* pg, int fromV, int toV){
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;//same with ALGraph.h
}

void ShowGraphEdgeInfo(ALGraph* pg){
	int i, vx;
	
	for(i=0; i<pg->numV; i++){//for each vertex
		printf("Edge that is connedted with %c: ", i+65);
		
		if(LFirst(&(pg->adjList[i]), &vx)){//access list element on each vertex.
			printf("%c ", vx+65);
			
			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx+65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2){
	if(data1<data2)
		return 0;
	else
		return 1;
}

int VisitVertex(ALGraph* pg, int visitV){//visit to visitV(enum)
	if(pg->visitInfo[visitV]==0){//not visit yet.
		pg->visitInfo[visitV]=1;//set visit!
		printf("%c ", visitV+65);//action for visit
		return TRUE;
	}
	return FALSE;
}

void DFShowGraphVertex(ALGraph* pg, int startV){//show at startV(enum)
	Stack stack;//for get traceback in DFS
	int visitV=startV;
	int nextV;
	
	StackInit(&stack);
	VisitVertex(pg, visitV);//visit work with set TRUE visitInfo. visit visitV first.
	int nextV;
	
	while(LFirst(&(pg->adjList[visitV]), &nextV)==TRUE){
		int visitFlag=FALSE;
		
		if(VisitVertex(pg, nextV)==TRUE){//try visit and if Success, push to stack for tracing, save current Vertex in visitV
			SPush(&stack, visitV);
			visitV=nextV;
			visitFlag=TRUE;//flag set for after handling
		} else{//we have to focus on it's if~else condition. if_true, else_false. if_false, else_true. do not confuse on visitV
			while(LNext(&(pg->adjList[visitV]), &nextV)==TRUE){
				if(VisitVertex(pg, nextV)==TRUE){
					SPush(&stack, visitV);
					visitV=nextV;//we don't use visitV in this code. it's just for extension.
					visitFlag=TRUE;
					break;//if visit success, break for eacaping
				}
			}
		}
		
		if(visitFlag==FALSE){//방문안했는데 
			if(SIsEmpty(&stack)==TRUE)//done without extra pop
				break;
			else
				visitV=SPop(&stack);//giva a change for contect
		}
	}
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);//다음 사용을 위하여 
}
