#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define MAX_TBL 100

typedef int (*HashFunc)(Key k);//for use functional pointer as type

typedef struct _table{
	Slot tbl[MAX_TBL];//table has array of Slot(Key, Value, State)
	HashFunc* hf;
} Table;

void TBLInit(Table* pt, HashFunc f);//���翣 HashFunc*�� �Ǿ��ִµ� �������� �ٲ�. ���ʿ� HashFunc��ü�� �Լ� �����Ͷ�� �� �ƴѰ�? �װ� typedef�ѰŰ� 

void TBLInsert(Table* pt, Key k, Value v);

Value TBLDelete(Table* pt, Key k);

Value TBLSearch(Table* pt, Key k);

#endif
