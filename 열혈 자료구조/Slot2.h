//충돌을 막기위한 방법으로 Linear Probing, Quadratic Probing, Double Hash가 대표적인 open addressing method이고
//대표적인 close addressing method로 우리가 사용할 chainnig이 있다. 

//체이닝을 사용하기위해 LinkedList를 사용할 것인데, 노드가 데이터를 가리키는 포인터를 소유하는 것이 이상적이다.(데이터에 노드기능을 추가하는 것 보다) 

#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

typedef struct _slot{
	Key key;
	Value val;
	//no state enum beacuse we will use chaining. not Linear proing
} Slot; 

#endif
