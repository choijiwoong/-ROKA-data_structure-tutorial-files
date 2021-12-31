#include <stdio.h>
#include "UsefulHeap.h"
//move, delete's complexity: O(log_2 n), time complexity: O(nlog_2 n). 힙에 넣으면 알아서 정렬됨 

int PriComp(int n1, int n2){
	return n2-n1;
	//return n1-n2;//reverse
}

void HeapSort(int arr[], int n, PriorityComp pc){//pc for call constructor of UsefulHeap
	Heap heap;
	int i;
	HeapInit(&heap, pc);
	
	for(i=0; i<n; i++)
		HInsert(&heap, arr[i]);//input to heap
	
	for(i=0; i<n; i++)
		arr[i]=HDelete(&heap);//output of heap
}

int main(){
	int arr[4]={3,4,2,1};
	int i;
	
	HeapSort(arr, sizeof(arr)/sizeof(int), PriComp);
	
	for(i=0; i<4; i++)
		printf("%d ", arr[i]);
	printf("\n");
		
	return 0;
}
