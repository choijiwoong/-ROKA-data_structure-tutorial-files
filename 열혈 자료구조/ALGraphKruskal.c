#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#include "PriorityQueue.h"//가중치 기준 간선 정렬을 위함 
#include "ALEdge.h"//가중치 포함된 간선을 나타내기 위한 구조체

int PQWeightComp(Edge d1, Edge d2){ return d1.wdight-d2.weight; }//ALEdge.h

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
	
	PQueueInit(&(pg->pqueue), PQWeightComp);//initialziation Priority Queue with comparator
}
	
void GraphDestroy(ALGraph* pg){
	if(pg->adjList!=NULL)
		free(pg->adjList);
		
	if(pg->visitInfo!=NULL)
		free(pg->visitInfo);//same with ALGraphDFS.h
}

void AddEdge(ALGraph* pg, int fromV, int toV, int weight){
	Edge edge={fromV, toV, weight};//make edge struct
	
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;//same with ALGraphBFS.h
	
	PEnqueue(&(pg->pqueue), edge);//save weight to priority queue
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
	}
}//same with ALGraphDFS.h


int visitVertex(ALGraph* pg, int visitV){//similar with VisitVertex of BFS, DFS. just printf is deleted
	if(int pg->visitInfo[visitV]==0){
		pg->visitInfo[visitV]=1;
		printf("%c ", visitV+65);
		return TRUE;
	}
	return FALSE;
}
void DFShowGraphVertex(ALGraph* pg){
	Stack stack;
	int visitV=startV;
	int nextV;
	
	StackInit(&stack);
	VisitVertex(pg, visitV);
	int nextV;
	
	while(LFirst(&(pg->adjList[visitV]), &nextV)==TRUE){
		int visitFlag=FALSE;
		
		if(VisitVertex(pg, nextV)==TRUE){
			SPush(&stack, visitV);
			visitV=nextV;
			visitFlag=TRUE;
		} else{
			while(LNext(&(pg->adjList[visitV]), &nextV)==TRUE){
				if(VisitVertex(pg, nextV)==TRUE){
					SPush(&stack, visitV);
					visitV=nextV;
					visitFlag=TRUE;
					break;
				}
			}
		}
		
		if(visitFlag==FALSE){
			if(SIsEmpty(&stack)==TRUE)
				break;
			else
				visitV=SPop(&stack);
		}
	}
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);//same with ALGraphDFS.h
}


//[Kruskal's sub functions]
void RemoveWayEdge(ALGraph* pg, int fromV, int toV){//consider direct.
	int edge;
	
	if(LFirst(&(pg->adjList[fromV]), &edge)){//search edge on List of fromV
		if(edge==toV){//if find, remove & return
			LRemove(&(pg->adjList[fromV]));
			return;
		} while(LNext(&(pg->adjList[fromV]), &edge)){
			if(edge==toV){
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}
void RemoveEdge(ALGraph* pg, int fromV, int toV){
	RemoveWayEdge(pg, fromV, toV);//consider undirected graph
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;//decrease num of Edges
}

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight){
	LInsert(&(pg->adjList[fromV]), toV);//insert directly yo adjlist.
	LInsert(&(pg->adjList[toV]), fromV);//consider direction
	(pg->numE)++;
}

int IsConnVertex(ALGraph* pg, int v1, int v2){
	Stack stack;//use DFS for check connection
	int visitV=v1;
	int nextV;
	
	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);
	
	while(LFirst(&(pg->adjList[visitV]), &next)==TRUE){//for search on all adjList
		int visitFlag=FALSE;
		if(nextV==v2){//find v1 is connected to v2
			memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
			return TRUE;//TRUE
		}
		
		if(VisitVertex(pg, nextV)==TRUE){//try visit for exexcuting next searching process by DFS.
			SPush(&stack, visitV);//push
			visitV=nextV;
			visitFlag=TRUE;
		} else{
			while(LNext(&(pg->adjList[visitV]), &nextV)==TRUE){//if first element is not, keep searcing next node by DFS
				if(nextV==v2){//same process with upper code.
					memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
					return TRUE;
				}
				
				if(VisitVertex(pg, next)==TRUE){//try c
					SPush(&stack, visitV);
					visitV=nextV;
					visitFlag=TRUE;
					break;
				}
			}
		}
		
		if(visitFlag==FALSE){
			if(SIsEmpty(&stack)==TRUE)
				break;
			else
				visitV=SPop(&stack);//after service for contect
		}
	}
	
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
	return FALSE;
}

void ConKruskalMST(ALGraph* pg){//KruskalMST main function
	Edge recvEdge[20];
	Edge edge;
	int eidx=0;
	int i;
	
	while(pg->numE+1>pg->numV){//condition of MST. Use kruskal algorism by decending
		edge=PDequeue(&(pg->pqueue));//remove biggest weight edge
		RemoveEdge(pg, edge.v1, edge.v2);//and remove
		
		if(!IsConnVertex(pg, edge.v1, edge.v2)){//if vertexes is not connected after removing
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);//recover
			recvEdge[edix++]=edge;//and add to recvEdge for additional work after this while loop.
		}
	}
	
	for(i=0; i<eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);//enqueue
}

void ShowGraphEdgeWeightInfo(ALGraph* pg){
	PQueue copyPQ=pg->pqueue;
	Edge edge;
	
	while(!PQIsEmpty(&copyPQ)){
		edge=PDequeue(&copyPQ);
		printf("(%c-%c), w: %d\n", edge.v1+65, edge.v2+65, edge.weight);
	}
}
