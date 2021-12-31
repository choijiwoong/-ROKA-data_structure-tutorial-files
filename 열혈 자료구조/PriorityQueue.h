#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"

typedef Heap PQueue;//retypedef of const in UsefulHeap.h
typedef HData PQData;

void PQueueInit(PQueue* ppq, PriorityComp pc);
int PQIsEmpty(PQueue* ppq);

void PEnqueue(PQueue* ppq, PQData data);
PQData PDequeue(PQueue* ppq);

#endif
