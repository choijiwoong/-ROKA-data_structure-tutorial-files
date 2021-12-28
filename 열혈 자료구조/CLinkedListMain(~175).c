#include <stdio.h>
#include "CLinkedList.h"

int main(){
	List list;
	int data, i, nodeNum;//buffer for argument of functions(saving data), for argument, buffer of LCount()
	ListInit(&list);
	
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	if(LFirst(&list, &data)){
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)*3-1; i++)//print 3 times for showing character of circle list.
			if(LNext(&list, &data))
				printf("%d ", data);
	}
	printf("\n");
	
	nodeNum=LCount(&list);//just save..
	if(nodeNum!=0){//remove even number in list
		LFirst(&list, &data);
		if(data%2==0)
			LRemove(&list);//benefit of cur. just call remove without allowing index for remove.
		
		for(i=0; i<nodeNum-1; i++){
			LNext(&list, &data);
			if(data%2==0)
				LRemove(&list);
		}
	}
	
	if(LFirst(&list, &data)){//print all once for check removing
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)-1; i++)
			if(LNext(&list, &data))
				printf("%d ", data);
	}
	
	return 0;
}

