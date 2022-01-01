#include <stdio.h>
//보간탐색을 인덱스의 값이 값의 정렬, 위치와 관계가 있다는 가정으로 탐색하는 이진탐색방법중 하나이다. 

int ISearch(int ar[], int first, int last, int target){
	int mid;
	if(ar[first]>target || ar[last]<target)//if(first>last)//wrong!_아래 재귀 호출의 -1, +1에서 추정된 mid가 적절치않으면 이전꺼에서 찾아보란 의미로 0을 리턴하는데 
		return -1;//이것이 결합하며 얽혀 전과 동일한 인자의 호출식이 발생할 수 있기에 값으로 비교한다. 
		
	//mid=(first+last)/2;//common binary search
	mid=((double)(target-ar[first])/(ar[last]-ar[first])*(last-first))+first;//use double for reducing loss_값의 차이로 보다 나은 인덱스 추정 
	
	if(ar[mid]==target)
		return mid;
	else if(target<ar[mid])
		return ISearch(ar, first, mid-1, target);
	else
		return ISearch(ar, mid+1, last, target);
}

int main(){
	int arr[]={1,3,5,7,9};
	int idx;
	
	idx=ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
	if(idx==-1)
		printf("Search Fail!");
	else
		printf("index of target: %d\n", idx);
	
	idx=ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 10);
	if(idx==-1)
		printf("Search Fail!\n");
	else
		printf("index of target: %d\n", idx);
		
	idx=ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);//Error Occur!
	if(idx==-1)
		printf("Search Fail!\n");
	else
		printf("index of target: %d\n", idx);
	
	return 0;
}
