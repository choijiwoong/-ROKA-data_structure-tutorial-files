#include <stdio.h>
#include "DLinkedList.h"

int WhoIsprecede(int d1, int d2){//In Main.c for user designed:)
	if(d1<d2)
		return 0;
	else
		return 1;
}

int main(){
	List list;
	int data;
	ListInit(&list);//initialization(Constructor)
	
	SetSortRule(&list, WhoIsPrecede);//register comp by user
	
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);
	printf("Current amount of data: %d\n", LCount(&list));
	
	//Access to all elements
	if(LFirst(&list, &data)){//print all
		printf("%d ",data);
		while(LNExt(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	
	//Remove
	if(LFirst(&list, &data)){//save first element to data
		if(data==22)//if first element is 22
			LRemove(&list);
		while(LNext(&list, &data))//save next element to data
			if(data==22)//if next element is 22 too
				LRemove(&list);
	}
	printf("Current amount of data: %d\n", LCount(&list));
	
	//print all
	if(LFirst(&list, &data)){
		printf("%d ", data);
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	
	return 0;
}
