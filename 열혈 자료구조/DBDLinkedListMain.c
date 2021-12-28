//����� ���� ����Ʈ�� LNext�� ���� LPrevious�Լ��� �߰��� ���̰�, �̴� cur setting���⸸ �ٸ��⿡ 
//���� ������ �ʾҴ�. �Ʒ��� Dummy�� �߰��� ����� ���� ����Ʈ�̴�. 
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
		if(!data&1)//�����غ���...0��°�� 2^0�̶� ���� �״�� ������... ���� �ٲٷ��� Ʋ����..����.. 
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
