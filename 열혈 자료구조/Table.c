#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table* pt, HashFunc f){//initialization of status to EMPTY & register hashfunction ¼öÁ¤ 
	int i;
	
	for(i=0; i<MAX_TBL; i++)
		(pt->tbl[i]).status=EMPTY;
		
	pt->hf=f;
}

void TBLInsert(Table* pt, Key k, Value v){
	int hv=pt->hf(k);//get hash value on key
	pt->tbl[hv].val=v;
	pt->tbl[hv].key=k;
	pt->tbl[hv].status=INUSE;//insert to index that is returned by hashfunction
}

Value TBLDelete(Table* pt, Key k){
	int hv=pt->hf(v);
	
	if((pt->tbl[hv).status!=INUSE){
		return NULL;
	} else{
		(pt->tbl[hv]).status=DELETED;
		return (pt->tbl[hv]).val;
	}
}

Value TBLSearch(Table* pt, Key k){
	int hv=pt->hf(k);
	
	if((pt->tbl[hv]).status!=INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).val;
}
