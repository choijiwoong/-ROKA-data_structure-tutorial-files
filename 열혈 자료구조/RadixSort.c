#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10//decimal

void RadixLSDSort(int arr[], int num, int maxLen){//max length of data
	Queue buckets[BUCKET_NUM];
	int bi, pos, di, divfac=1, radix;
	
	for(bi=0; bi<BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);//initialization of queue array(버킷 초기화) 
	
	for(pos=0; pos<maxLen; pos++){//for each space_모든 자리수를 반복할건데, pos는 쓰지 않음. bubble느낌으로 for돌리는 개념인듯 
		for(di=0; di<num; di++){//for each elements_모든 항목들의 
			radix=(arr[di]/divfac)%10;//divide element by divfac, %10 for get one space
			Enqueue(&buckets[radix], arr[di]);//all element is enqueued
		}//항목들의 한 자리씩 radix에 따라 bucket에 저장. 
		
		for(bi=0,di=0; bi<BUCKET_NUM; bi++){//for each bucket
			while(!QIsEmpty(&buckets[bi]))//queue has data
				arr[di++]=Dequeue(&buckets[bi]);//save data to arr
		}//array에 저장 bucket순으로 
		
		divfac*=10;//work per step_BUCKET_NUM만큼 반복. 
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
