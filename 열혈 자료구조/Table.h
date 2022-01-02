#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define MAX_TBL 100

typedef int (*HashFunc)(Key k);//for use functional pointer as type

typedef struct _table{
	Slot tbl[MAX_TBL];//table has array of Slot(Key, Value, State)
	HashFunc* hf;
} Table;

void TBLInit(Table* pt, HashFunc f);//교재엔 HashFunc*로 되어있는데 오류떠서 바꿈. 애초에 HashFunc자체가 함수 포인터라는 거 아닌가? 그걸 typedef한거고 

void TBLInsert(Table* pt, Key k, Value v);

Value TBLDelete(Table* pt, Key k);

Value TBLSearch(Table* pt, Key k);

#endif
