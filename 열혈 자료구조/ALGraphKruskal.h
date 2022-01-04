#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRAPH_KRUSKAL__

#include "DLinkedList.h"
#include "PriorityQueue.h"//����ġ ���� ���� ������ ���� 
#include "ALEdge.h"//����ġ ���Ե� ������ ��Ÿ���� ���� ����ü
//UsefulHeap����ҰŰű⿡ �����͸� Edge�� �ٲ���. 

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
