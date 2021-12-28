//양방향 연결 리스트는 LNext와 같은 LPrevious함수가 추가될 뿐이고, 이는 cur setting방향만 다르기에 
//따로 담지는 않았다. 아래는 Dummy가 추가된 양방향 연결 리스트이다. 
#include <stdio.h>
#include "DBDLinkedList.h"

int main(){
	List list;
	int data;
	ListInit(&list);//initialization
	
	LInsert(&list, 1); LInsert(&list, 2);//insert
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);
	
	if(LFirst(&list, &data)){//print all
		printf("%d ", data);
		while(LNext(&list, &data))
			printf("%d ", data);
		printf("\n");
	}
	
	if(LFirst(&list, &data)){//remove even number
		if(!data&1)//생각해보니...0번째는 2^0이라 숫자 그대로 나오지... 괜히 바꾸려다 틀릴뻔..데헷.. 
			LRemove(&list);
		while(LNext(&list, &data))
			if(!data&1)
				LRemove(&list);
	}
	
	if(LFirst(&list, data)){
		printf("%d ", data);
		while(LNext(&list, &data))
			printf("%d ", data);
		printf("\n\n");
	}
	
	return 0;
}
