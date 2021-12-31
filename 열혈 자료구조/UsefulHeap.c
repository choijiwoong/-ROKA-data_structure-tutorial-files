#include "UsefulHeap.h"

void HeapInit(Heap* ph, PriorityComp pc){
	ph->numOfData=0;
	ph->comp=pc;
}

int HIsEmpty(HEap* ph){//empty state?
	if(ph->cumOfData==0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx){//parent's idx
	return idx/2;//divide integerally
}
int GetLChildIDX(int idx){//left child's idx
	return idx*2;
}
int GetRChildIDX(int idx){//right child's idx
	return GetLChildIDX(idx)+1;//idx*2+1
}

int GetHiPriChildIDX(Head* ph, int idx){//by comparator
	if(GetLChildIDX(idx)>ph->numOfData){
		return 0;
	} else if(GetLChildIDX(idx)==ph->numOfData){
		return GetLChildIDX(idx);
	} else{
		//if(ph->heapArr[GetLChildIDX(idx)].pr > ph->headArr[GetRChildIDX(idx)].pr)//내림차순
		if( ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) <0 ) //comp return -
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData data){
	int idx=ph->numOfData+1;//like add one node at last(size is enough by HEAP_LEN)
	
	while(idx!=1){//until root node. bottom to up
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]>0)){//compare data, it's parent
			//if data is first than it's parent
			ph->heapArr[idx]=ph->heapArr[GetParentIDX(idx)];//down parent to it's current location(level down)
			idx=GetParentIDX(idx);//refresh idx(like idx++)
		} else{//*if data if last than it's parent, move data to current node not parent node.*
			break;
		}
	}
	
	ph->heapArr[idx]=data;//actual move of data
	ph->numOfData++;
}

HData HDelete(Heap* ph){
	HData retData=ph->heapArr[1];//for return
	HData lastElem=ph->heapArr[ph->numOfData];//for move data like backup..?
	
	int parentIdx=1;//variables for for loop
	int childIdx;
	
	//up to bottom
	while(childIdx=GetHiPriChildIdx(ph, parentIdx)){//get ph's Child
		if(ph->comp(lastElem, ph->heapArr[childIdx])>=0)//compare data, it's child
			break;//if data is first than child, break
		
		ph->heapArr[parentIdx]=ph->heapArr[childIdx];//up child to parent's location. level++
		parentIdx=childIdx;//refresh
	}
	
	ph->heapArr[parentIdx]=lastElem;//actual data movd
	ph->numOfData--;
	
	return retData;//return initial root's data
}
