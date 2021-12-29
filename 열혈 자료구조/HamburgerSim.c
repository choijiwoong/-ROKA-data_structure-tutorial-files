//CircularQueue Simulation Example
//�ùķ��̼��� ���� ������ 4���� ���� 
//1. �ֹ��ð��� ���ɽð� 1�ð��̰� ���� 15�ʿ� 1�� �ֹ��� �Ѵ�. 
//2. �� ���� ���� �ϳ��� ���Ÿ��� �ֹ��Ѵ�.
//3. �ܹ��Ÿ� ����� ����� 1���̸� ���ÿ� 2�� �̻��� ���Ÿ� ������ �ʴ´�.
//4. �ֹ��� �޴��� ���� ���� ���� ���ǿ��� ���ͼ� ����Ѵ�. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define CUS_COME_TERM 15//term of customer's order(sec)

#define CHE_BUR 0//const of burger like enum
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12//Term for making vurger
#define BUL_TERM 15
#define DUB_TERM 24

int main(){
	int makeProc=0;//current state of making hamburgers
	int cheOrder=0, bulOrder=0, dubOrder=0;
	int sec;
	
	Queue que;
	
	QueueInit(&que);
	srand(time(NULL));
	
	for(sec=0; sec<2600; sec++){
		if(sec%CUS_COME_TERM==0){
			switch(rand()%3){
				case CHE_BUR:
					Enqueue(&que, CHE_TERM);//add term for making burger
					cheOrder++;
					break;
				
				case BUL_BUR:
					Enqueue(&que, BUL_TERM);
					bulOrder++;
					break;
					
				case DUB_BUR:
					Enqueue(&que, DUB_TERM);
					dubOrder++;
					break;
			}
		}
		
		if(makeProc<=0 && !QIsEmpty(&que))
			makeProc=Dequeue(&que);
			
		makeProc--;
	}
	
	printf("Simulation Report!\n");
	printf("-Cheese burger: %d\n", cheOrder);
	printf("-Bulgogi burger: %d\n", bulOrder);
	printf("-Double burger: %d\n", dubOrder);
	printf("-Waiting room size: %d\n", QUE_LEN);
	
	return 0;
}
