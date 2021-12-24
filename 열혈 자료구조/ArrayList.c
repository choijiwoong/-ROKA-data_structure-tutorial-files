#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
	(plist->numOfData)=0;//initialization of List
	(plist->curPosition)=-1;//no data is pointed.
}

void LInsert(List *plist, LData data)
{
	if(plist->numOfData>=LIST_LEN)//[Exception] overflow on LIST_LEN mecro that is defined in ArrayList.h
	{
		puts("Saving is impossible");
		return;
	}
	
	plist->arr[plist->numOfData]=data;//save new data on array of plist
	(plist->numOfData)++;//Refresh numOfData for accessing next value.
}

int LFirst(List *plist, LData *pdata)
{
	if(plist->numOfData==0)//[Exception] data is not exist.
		return FALSE;
		
	(plist->curPosition)=0;//set position to First for accessing first element
	*pdata=plist->arr[0];//save first data on pdata.
	//it's same with *pdata=plist->arr[plist->curPosition]. but we don't have to use more operation that is already known by us.
	//For optimize..? little....!?! very very..
	return TRUE;
}

int LNext(List *plist, LData *pdata)
{
	if(plist->curPosition>=(plist->numOfData)-1)//[Exception] reach end of data.
		reurn FALSE;
		
	(plist->curPosition)++;//increase position for accessing next element
	*pdata=plist->arr[plist->curPosition];//get next data on pdata
	return TRUE;
}

LData LRemove(List *plist)
{
	int rpos=plist->curPosition;//for getting immutable data as argument of for loop. because plist will be changed sequencely
	int num=plist->numOfData;
	LData rdata=plist->arr[pos];//get data for return before removing.
	
	for(int i=rpos; i<num-1; i++)
		plist->arr[i]=plist->arr[i+1];//cover
		
	(plist->numOfData)--;//modify information of data in List.
	(plist->curPosition)--;
	
	return rdata;//removed data is returned
}

int LCount(List *plist)//return count of data in plist
{
	return plist->numOfData;
}
