#include <stdio.h>
#include <stdlib.h>
//compare: nlog2_n, move: nlog2_n. allocation이 필요하지만, 이는 연결리스트로 구현하면 해결되는 단점이다. 

void MergeTwoArea(int arr[], int left, int mid, int right){
	int fIdx=left;//2(left, fidx)378(mid)1(ridx)456(right)
	int rIdx=mid+1;
	int i;
	
	int* sortArr=(int*)malloc(sizeof(int)*(right+1));
	int sIdx=left;
	
	while(fIdx<=mid && rIdx<=right){//until one partition end. if one array is already sorted, escape because additional sort is not meaningful.
		if(arr[fIdx]<=arr[rIdx])//compare fIdx, rIdx 
			sortArr[sIdx]=arr[fIdx++];//save and increse saved element's index only 
		else
			sortArr[sIdx]=arr[rIdx++];
			
		sIdx++;//saved array's index. convert array's
	}
	
	if(fIdx>mid){//save left element
		for(i=rIdx; i<=right; i++,sIdx++)
			sortArr[sIdx]=arr[i];
	} else{
		for(i=fIdx; i<=mid; i++,sIdx++)
			sortArr[sIdx]=arr[i];
	}
	
	for(i=left; i<=right; i++)
		arr[i]=sortArr[i];//save sorted data to argument's array
	
	free(sortArr);//deallocation
}

void MergeSort(int arr[], int left, int right){
	int mid;
	
	if(left<right){
		mid=(left+right)/2;
		
		MergeSort(arr, left, mid);//Divide recursively
		MergeSort(arr, mid+1, right);
		MergeTwoArea(arr, left, mid, right);//Conquer all divided elements
	}
}

int main(){
	int arr[7]={3,2,4,1,7,6,5};
	int i;
	
	MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);
	
	for(i=0; i<7; i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	return 0;
}
