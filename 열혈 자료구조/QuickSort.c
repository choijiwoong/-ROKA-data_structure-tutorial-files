#include <stdio.h>
//compare: O(n^2)_�־��� ���, but �ʱ� pivot���� ������� O(nlog2_n)�� ������ ���� �� �ִ�. �� ���� ��������� ���� ���� �ӵ��� ������ �ڶ��Ѵ�. 

int MedianOfThree(int arr[], int left, int right){//������ �ǹ� ���ϴ� ���� 
	int samples[3]={left, (left+right)/2, right};//samples for middle value by index
	
	if(arr[samples[0]]>arr[samples[1]])
		Swap(samples, 0, 1);
	if(arr[samples[1]]>arr[samples[2]])
		Swap(samples, 1, 2);
	if(arr[samples[0]]>arr[samples[1]])
		Swap(samples, 0, 1);
		
	return samples[1];
} //������ pivot�� left�� ��ġ�ǰ� ������ ���� �״�� �̿��ϱ� ���� ���� pivot�� left�� �ű�� ������ Partition�� �߰��Ѵ�. 

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
		while(pivot>=arr[low] && low<=right)//while(pivot>arr[low])//pivot���� ū ���� �ε����� low�� ��� 
			low++;
		while(pivot<=arr[high] && high>=(left+1))//while(pivot<arr[high])//pivot���� ���� ����  �ε����� high�� ��� 
			high--;
		if(low<=high)//ū���� �������� ��ġ�� ����Ǿ�� �Ѵٸ� 
			Swap(arr, low, high);
	}
	
	Swap(arr, left, high);//left(pivot�� default index�� left_����)�� high�� swap�ϸ� pivot�̵� 
	//pivot�������� ������ pivot���� ������, ������ ū�Ÿ� �� �ְ� �ȴ�. 
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
	//while condition�� �����ڸ� =�� �����ϰ� �Ͽ� ���� ������ ������ ��ȸ�� ��� �ϵ�,
	//�׷��ٸ� ������ ���(�迭�� ���� ����)�� �Ѵ� ������ �߻��ϱ⿡ while�� ���˻絵 �߰����ֱ�� ����. 
	
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
