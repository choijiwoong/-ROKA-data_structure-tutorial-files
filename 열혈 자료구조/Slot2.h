//�浹�� �������� ������� Linear Probing, Quadratic Probing, Double Hash�� ��ǥ���� open addressing method�̰�
//��ǥ���� close addressing method�� �츮�� ����� chainnig�� �ִ�. 

//ü�̴��� ����ϱ����� LinkedList�� ����� ���ε�, ��尡 �����͸� ����Ű�� �����͸� �����ϴ� ���� �̻����̴�.(�����Ϳ� ������� �߰��ϴ� �� ����) 

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
