#include <stdio.h>
#include <stdlib.h>
#include "Table2.h"
#include "DLinkedList.h"

void TBLInit(Table* pt, HashFunc f){
	int i;
	for(i=0; i<MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));//list init in tbl's array
	
	pt->hf=f;
}

void TBLInsert(Table* pt, Key k, Value v){
	int hv=pt->hf(k);//get hash value
	Slot ns={k, v};
	
	if(TBLSearch(pt, k)!=NULL){
		printf("Duplicated key error!");
		return;
	} else{
		LInsert(*(pt->tbl[hv]), ns);//insert to hashed index's list.
	}
}

Value TBLDelete(Table* pt, Key k){
	int hv=pt->hf(k);//get hashed index by k
	Slot cSlot;//for use like buffer
	
	if(LFirst(&(pt->tbl[hv]), &cSlot)){//first element to cSlot
		if(cSlot.key==k){//if find
			LRemove(&(pt->tbl[hv]));//remove
			return cSlot.val;//return 
		} else{
			while(LNext(&(pt->tbl[hv]), &cSlot)){//do next elements too
				if(cSlot.key==k){
					LRemove(&(pt->tbl[hv]));
					return cSlot.val;
				}
			}
		}
	}
	
	//return NULL;//반환되는 값이 NULL인지 0인지를 구별하기 위함. 물론 header에서 typedef Person * Value로 pointer형임을 명시하긴 했다. 
	return FALSE;
}

Value TBLSearch(Table* pt, Key k){
	int hv=pt->hf(k);
	Slot cSlot;
	
	if(LFirst(&(pt->tbl[hv]), &cSlot)){//get one element of list
		if(cSlot.key==k){
			return cSlot.val;//return value
		} else{
			while(LNext(&(pt->tbl[hv]), &cSlot)){
				if(cSlot.key==k)
					return cSlot.val;
			}
		}
	}
	
	//return NULL;
	return FALSE;
}
