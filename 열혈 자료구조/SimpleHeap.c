#include "SimpleHeap.h"

void HeapInit(Heap* ph){
	ph-numOfData=0;
}

int HIsEmpty(Heap* ph){
	if(ph->numOfData==0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx){
	return idx/2;
}
int GetLChildIDX(int idx){
	return idx*2;
}
int GetRChildIDX(int idx){
	return GetLChildIDX(idx)+1;
}

int GetHiPriChildIDX(Heap* ph, int idx){
	if(GetLChildIDX(idx)>ph->numOfData){//no child
		return 0;
	} else if(GetLChildIDX(idx)==ph->numOfData){//one child
		return GetLChildIDX(idx);//LChild beacuse of complete binary tree
	} else{
		if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)//compare priority in childs
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData data, Prioridy pr){
	int idx=ph->numOfData+1;
	HeapElem nelem={pr, data};
	
	while(idx!=1){//bottom to up
		if( pr< (ph->heapArr[GetParentIDX(idx)].pr) ){//compare by pr member variable directly witout comparator that user design
			ph->heapArr[idx]=ph->heapArr[GetParentIDX(idx)];
			idx=GetParentIDX(idx);
		} else{
			break;
		}
	}
	
	ph->heapArr[idx]=nelem;
	ph->numOfData++;
}

HData HDelete(Heap* ph){
	HData retData=(ph->heapArr[1]).data;
	HeapElem lastElem=ph->heapArr[ph->numOfData];
	
	int partentIdx=1;
	int childIdx;
	
	while(childIdx=GetHiPriChildIDX(ph, parentIdx)){//up to bottom
		if(lastElem.pr<ph->heapArr[childIdx].pr)
			break;
		
		ph->heapArr[parentIdx]=ph->heapArr[childIdx];
		parentIdx=childIdx;
	}
	
	ph->heapArr[parentIdx]=lastElem;
	ph->numOfData--;
	
	return retData;
}
