#include <stdio.h>
//����Ž���� �ε����� ���� ���� ����, ��ġ�� ���谡 �ִٴ� �������� Ž���ϴ� ����Ž������� �ϳ��̴�. 

int ISearch(int ar[], int first, int last, int target){
	int mid;
	if(ar[first]>target || ar[last]<target)//if(first>last)//wrong!_�Ʒ� ��� ȣ���� -1, +1���� ������ mid�� ����ġ������ ���������� ã�ƺ��� �ǹ̷� 0�� �����ϴµ� 
		return -1;//�̰��� �����ϸ� ���� ���� ������ ������ ȣ����� �߻��� �� �ֱ⿡ ������ ���Ѵ�. 
		
	//mid=(first+last)/2;//common binary search
	mid=((double)(target-ar[first])/(ar[last]-ar[first])*(last-first))+first;//use double for reducing loss_���� ���̷� ���� ���� �ε��� ���� 
	
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
