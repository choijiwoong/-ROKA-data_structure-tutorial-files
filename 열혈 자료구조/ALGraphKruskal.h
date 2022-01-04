#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRAPH_KRUSKAL__

#include "DLinkedList.h"
#include "PriorityQueue.h"//가중치 기준 간선 정렬을 위함 
#include "ALEdge.h"//가중치 포함된 간선을 나타내기 위한 구조체
//UsefulHeap사용할거거기에 데이터를 Edge로 바꾸자. 

enum{A, B, C, D, E, F, G, H, I, J};

typedef struct _ual{
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
	PQueue pqueue;
} ALGraph;

void GraphInit(ALGraph* pg, int nv);//some dif
void GraphDestroy(ALGraph* pg);//some dif
void AddEdge(ALGraph* pg, int fromV, int toV, int weight); //some dif
void ShowGraphEdgeInfo(ALGraph* pg);//same
void DFShowGraphVertex(ALGraph* pg);//same
void ConKruskalMST(ALGraph* pg);//new
void ShowGraphEdgeWeightInfo(ALGraph* pg);//new

#endif
