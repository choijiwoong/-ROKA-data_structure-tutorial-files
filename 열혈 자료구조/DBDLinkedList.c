#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List* plist){//list initialization. (It's important to DBDLinkedList for direction by head, tail)
	plist->head=(Node*)malloc(sizeof(Node));
	plist->tail=(Node*)malloc(sizeof(Node));
	
	plist->head->prev=NULL;
	plist->head->next=plist->tail;//head points tail by next. because it's binary linked list. it has direction.
	
	plist->tail->next=NULL;
	plist->tail->prev=plist->head;//tail points head by prev

	plist->numOfData=0;
}

void LInsert(List* plist, Data data){//insert newNode to tail.
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;//new Node initialization
	
	//newNode set & plist's tail set
	newNode->prev=plist->tail->prev;//newNode's prev set. tail&head is Dummy!
	plist->tail->prev->next=newNode;//set tail's PREV's next to newNode
	
	newNode->next=plist->tail;//newNode's next set.
	plist->tail->prev=newNode;//set tail's prev
	
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata){
	if(plist->head->next==plist->tail)
		return FALSE;//no data
		
	plist->cur=plist->head->next;//cur set to head's next (because of Dummy Node for consistency)
	*pdata=plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata){
	if(plist->cur->next==plist->tail)//if next data is null(dummy_tail)
		return FALSE;
		
	plist->cur=plist->cur->next;//set cur
	*pdata=plist->cur->data;//approach by cur
	return TRUE;
}

Data LRemove(List* plist){
	Node* rpos=plist->cur;//for free(delete)
	Data remv=rpos->data;//for return
	
	plist->cur->prev->next=plist->cur->next;//cur's prev, next set
	plist->cur->next->prev=plist->cur->prev;
	
	plist->cur=plist->cur->prev;//cur set
	
	free(rpos);
	(plist->numOfData)--;
	return remv;
}

int LCount(List* plist){
	return plist->numOfData;
}
