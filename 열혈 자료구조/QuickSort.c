#include <stdio.h>
//compare: O(n^2)_최악의 경우, but 초기 pivot설정 방법으로 O(nlog2_n)과 가깝게 만들 수 있다. 그 덕에 평균적으로 가장 빠른 속도의 정렬을 자랑한다. 

int MedianOfThree(int arr[], int left, int right){//최적의 피벗 구하는 도구 
	int samples[3]={left, (left+right)/2, right};//samples for middle value by index
	
	if(arr[samples[0]]>arr[samples[1]])
		Swap(samples, 0, 1);
	if(arr[samples[1]]>arr[samples[2]])
		Swap(samples, 1, 2);
	if(arr[samples[0]]>arr[samples[1]])
		Swap(samples, 0, 1);
		
	return samples[1];
} //기존의 pivot이 left에 배치되게 구현한 것을 그대로 이용하기 위해 구한 pivot을 left로 옮기는 연산을 Partition에 추가한다. 

void Swap(int arr[], int idx1, int idx2){
	int temp=arr[idx1];
	arr[idx1]=arr[idx2];
	arr[idx2]=temp;
}

int Partition(int arr[], int left, int right){
	 int pIdx=MedianOfThree(arr, left, right);//choose pivot
	 int pivot=arr[pIdx];//initial value of pivot set left value
	
	int low=left+1;
	int high=right;
	
	 Swap(arr, left, pIdx);
	 printf("%d pivot by MedianOfThree: %d\n", pivot);
	
	while(low<=high){
		while(pivot>=arr[low] && low<=right)//while(pivot>arr[low])//pivot보다 큰 곳의 인덱스를 low에 얻기 
			low++;
		while(pivot<=arr[high] && high>=(left+1))//while(pivot<arr[high])//pivot보다 작은 곳의  인덱스를 high에 얻기 
			high--;
		if(low<=high)//큰곳과 작은곳의 위치가 변경되어야 한다면 
			Swap(arr, low, high);
	}
	
	Swap(arr, left, high);//left(pivot의 default index는 left_가정)와 high를 swap하며 pivot이동 
	//pivot기준으로 좌측은 pivot보다 작은거, 우측은 큰거만 모여 있게 된다. 
	return high;
}

void QuickSort(int arr[], int left, int right){
	if(left<=right){
		int pivot=Partition(arr, left, right);
		QuickSort(arr, left, pivot-1);
		QuickSort(arr, pivot+1, right);
	}
}

int main(){
	int arr[7]={3,2,4,1,7,6,5};
	int arr2[3]={3,3,3};//Error Occur because while(low<=high) is always TRUE
	//while condition의 연산자를 =도 가능하게 하여 각각 증가와 감소의 기회를 얻게 하되,
	//그렇다면 기존의 경계(배열의 정렬 범위)를 넘는 문제가 발생하기에 while에 경계검사도 추가해주기로 하자. 
	
	int len=sizeof(arr)/sizeof(int);
	int len2=sizeof(arr2)/sizeof(int);
	int i;
	
	printf("arr");
	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
	printf("\n\n arr2");
	QuickSort(arr2, 0, sizeof(arr2)/sizeof(int)-1);
	printf("\n");
	
	for(i=0; i<len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	
	for(i=0; i<len2; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	
	return 0;
}
