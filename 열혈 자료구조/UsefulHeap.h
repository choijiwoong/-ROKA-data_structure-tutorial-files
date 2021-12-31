//우선순위를 index를 사용하여 배치하는 array의 경우 shift연산의 리스트와 최악의 경우 모든 데이터를 비교해야하며,
//연결리스트로 사용할때는 shift리스트는 없지만 최악의 리스트는 여전히 존재하기에
//레벨이 높을수록 값이 낮아지는 완전이진트리_Heap을 사용한다.

//데이터의 추가는 최저노드에 한 뒤 올라가며 탐색한다. 삭제는 최저노드를 루트로 옮긴뒤에 내리며 탐색한다.

//힙은 연결리스트로 구현하면 새 노드를 마지막 위치에 추가하는 것이 어렵기에? 배열을 기반으로 구현한다.

//인덱스 0은 구현상의 편의를 위해 사용하지 않는다. 

#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int (*PriorityComp)(HData d1, HData d2);

typedef struct _heap{
	PriorityComp* comp;//user designed in upper PriorityComp format.
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

#endif
