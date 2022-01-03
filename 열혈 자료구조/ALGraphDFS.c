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
	
	while(LFirst(&(pg->adjList[visitV]), &nextV)==TRUE){//visitV에 해당하는 리스트의 첫 항목을 nextV에 저장 
		int visitFlag=FALSE;//1. 스타트 vertex의 첫 리스트 항목을 next에 저장 
		
		if(VisitVertex(pg, nextV)==TRUE){//방문에 시도하고 성공한다면 
			SPush(&stack, visitV);//자취를 stack에 push 
			visitV=nextV;//방문 완료된 항목을 visitV에 저장 for next element접근 
			//2. 1의 항목을 visitV에 저장. visitV는 방문할 vertex를 가리킴. 즉 스타트 리스트의 첫 항목을 다음 방문할 vertex로 저장 
			//sol2) visitV는 다음에 노드에 접근되면 기존의 노드(vertex)를 지나갔다고 스택에 push할 목적이 전부임.
			//고로 지금 visitV를 현재 우리가 방문한 노드로 담고 다음 접근때 접근이 성공한다면 그때 visitV를 Push하는거지! 
			visitFlag=TRUE;//flag set for after handling
		} else{//sol1) 방문에 성공하지 못했다면!!! visitV가 next로 세팅되지 않음!! 고로 아래에서 계속 다음 항목 접근 시도함. 
			while(LNext(&(pg->adjList[visitV]), &nextV)==TRUE){//다음 항목을 nextV에 저장 
			//3. 2의 리스트에서 다음 항목을 nextV에 저장. 계속 방문 시도? 
				if(VisitVertex(pg, nextV)==TRUE){//이상의 과정 반복 
					SPush(&stack, visitV);
					visitV=nextV;
					visitFlag=TRUE;
					break;
				}
			}
		}
		
		if(visitFlag==FALSE){//방문안했는데 
			if(SIsEmpty(&stack)==TRUE)//스택도 비어있다 그럼 break 
				break;
			else//스택에 뭐 있으면 pop하여 연락의 기회 준다. 
				visitV=SPop(&stack);
		}
	}
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);//다음 사용을 위하여 
}
