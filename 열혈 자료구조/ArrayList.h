#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

//mecro for expression of true, false
#define TRUE 1
#define FALSE 0

//Array's length
#define LIST_LEN 100
//typedef int LData;//for convenience of changing type
typedef Point* Ldata;//Pointer type for handling by ADT function. we can call destructor regardless of type. 
					//we can just put it in destructor function(that's argument is pointer type.)

typedef struct __ArrayList//structure of ArrayList we will use
{
	LData arr[LIST_LEN];
	itn numOfData;
	int curPosition;
}ArrayList;

typedef ArrayList List;//ArrayList is included in List. Another List is Linked List.

void ListInit(List *plist);//initialization
void LInsert(List *plist, LData data);//insert data

int LFirst(List *plist, LData *pdata);//save first data to pdata
int LNext(List *plist, LData *pdata);//save next data to pdata

LData LRemove(List *plist);//remove one element
int LCount(List *plist);//number of data that is saving.

#endif
