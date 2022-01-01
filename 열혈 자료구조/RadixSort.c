#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10//decimal

void RadixLSDSort(int arr[], int num, int maxLen){//max length of data
	Queue buckets[BUCKET_NUM];
	int bi, pos, di, divfac=1, radix;
	
	for(bi=0; bi<BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);//initialization of queue array(��Ŷ �ʱ�ȭ) 
	
	for(pos=0; pos<maxLen; pos++){//for each space_��� �ڸ����� �ݺ��Ұǵ�, pos�� ���� ����. bubble�������� for������ �����ε� 
		for(di=0; di<num; di++){//for each elements_��� �׸���� 
			radix=(arr[di]/divfac)%10;//divide element by divfac, %10 for get one space
			Enqueue(&buckets[radix], arr[di]);//all element is enqueued
		}//�׸���� �� �ڸ��� radix�� ���� bucket�� ����. 
		
		for(bi=0,di=0; bi<BUCKET_NUM; bi++){//for each bucket
			while(!QIsEmpty(&buckets[bi]))//queue has data
				arr[di++]=Dequeue(&buckets[bi]);//save data to arr
		}//array�� ���� bucket������ 
		
		divfac*=10;//work per step_BUCKET_NUM��ŭ �ݺ�. 
	}
}

int main(){
	int arr[7]={13, 212, 14, 7141, 10987, 6, 15};
	int len=sizeof(arr)/sizeof(int);
	int i;
	
	RadixSort(arr, len, 5);
	
	for(i=0; i<len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}
