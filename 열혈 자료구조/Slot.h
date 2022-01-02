#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;//Value is pointer type

enum SlotStatus{EMPTY, DELETED, INUSE};//distinguish EMPTY & DELETED in collepse

typedef struct _slot{
	Key key;
	Value val;
	enum SlotStatus status;
} Slot;

#endif
