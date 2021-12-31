#include <stdio.h>
//compare: O(n&2), move: O(n^2). 정렬된 상태면 아무것도 안함. 

void InserSort(int arr[], int n){
	int i, j, insData;
	
	for(i=1; i<n; i++){
		insData=arr[i];//data will be inserted
		
		for(j=i-1; j>=0; j--){//compare elements with previous data of insData
			if(arr[j]>insData)//make space for insertion
				arr[j+1]=arr[j];
			else
				break;
		}
		
		arr[j+1]=insData;//move data on correct space
	}
} 

int main(){
	int arr[5]={5,3,2,4,1};
	int i;
	
	InserSort(arr, sizeof(arr)/sizeof(int));
	
	for(i=0; i<5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}
