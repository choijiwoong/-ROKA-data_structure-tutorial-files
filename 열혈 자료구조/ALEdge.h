//Simple path+시작끝 동일= cycle, non-cycle=spanning tree, 신장트리의 가중치 합 최소를 minimum cost spanning tree, minimum spanning tree
//MST라고 표현. MST는 Kruskal알고리즘(가중치기준 정렬(오름내림) 후 MST가 될때까지 간선 선택 or 삭제
//Prim알고리즘은 하나의 vertex를 시작으로 MST될때까지 트리 확장.
//크루스칼의 경우 오름차순은 낮은 가중치부터 추가하며 사이클시 추가하지 않고 MST가 되면 종료(edge+1=vertex)
//내림의 경우 높은 가중치부터 제거하며 두 정점을 연결하는 유일한 간선은 제거X, MST가 되면 종료(edge+1=vertex)

//간선의 가중치 정보를 저장하기 위함 
#ifndef __AL_EDGE__ 
#define __AL_EDGE__

typedef struct _edge{
	int v1;
	int v2;
	int weight;
} Edge;

#endif
