#include <stdio.h>
//compare: O(n^2), move: O(n^2). 이미 정렬된 데이터도 존나 돌림 

void BubbleSort(int arr[], int n){
	int i, j, temp;
	
	for(i=0; i<n-1; i++){
		for(j=0; j<(n-i)-1; j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main(){
	int arr[4]={3,2,4,1};
	int i;
	
	BubbleSort(arr, sizeof(arr)/sizeof(int));
	
	for(i=0; i<4; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}
