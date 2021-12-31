//�켱������ index�� ����Ͽ� ��ġ�ϴ� array�� ��� shift������ ����Ʈ�� �־��� ��� ��� �����͸� ���ؾ��ϸ�,
//���Ḯ��Ʈ�� ����Ҷ��� shift����Ʈ�� ������ �־��� ����Ʈ�� ������ �����ϱ⿡
//������ �������� ���� �������� ��������Ʈ��_Heap�� ����Ѵ�.

//�������� �߰��� ������忡 �� �� �ö󰡸� Ž���Ѵ�. ������ ������带 ��Ʈ�� �ű�ڿ� ������ Ž���Ѵ�.

//���� ���Ḯ��Ʈ�� �����ϸ� �� ��带 ������ ��ġ�� �߰��ϴ� ���� ��Ʊ⿡? �迭�� ������� �����Ѵ�.

//�ε��� 0�� �������� ���Ǹ� ���� ������� �ʴ´�. 

#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int (*PriorityComp)(HData d1, HData d2);

typedef struct _heap{
	PriorityComp* comp;//user designed in upper PriorityComp format.
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

#endif
