#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist){
	plist->head=(Node*)malloc(sizeof(Node));
	plist->head->next=NULL;//dummy's next is null
	plist->comp=null;
	plist->numOfData=0;
}

void FInsert(List *plist, LData data){
	Node *newNode=(Node*)malloc(sizeof(Node));//allocate space for adding new element
	newNode->data=data;//set data
	
	newNode->next=plist->head->next;//connect newNode's next
	plist->head->next=newNode;//connect head's next
	
	(plist->numOfData)++;
}

void SInsert(List *plist, LData data){
	Node *newNode=(Node*)malloc(sizeof(Node));
	Node *pred=plist->head;//for modify sequence successfully because DLinkedList cannot approach last element. only by using next element. so save pred element
	newNode->data=data;
	
	while(pred->next!=NULL && plist->comp(data, pred->next->data)!=0){//compare by plist's comp with pred's next data. like future value.
		pred=pred->next;
	}
	
	newNode->next=pred->next;//set newNode by using pred.
	pred->next=newNode;
	
	(plist->numOfData)++;
}

void LInsert(List *plist, LData data){
	if(plist->comp==NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata){
	if(plist->head->next==NULL)//empty list
		return FALSE;
		
	plist->before=plist->head;//reset before & cur to correct location.
	plist->cur=plist->head->next;
	
	*pdata=plist->cur->data;//access by using cur->data
	
	return TRUE;
}

int LNext(List *plist ,LData *pdata){
	if(plist->cur->next==NULL)
		return FALSE;
		
	plist->before=plist->cur;//set before & cur
	plist->cur=plist->cur->next;
	
	*pdata=plist->cur->data;
	return TRUE;
}

LData LRemove(list *plist){//by using cur
	Node *rpos=plist->cur;//for free
	LData rdata=rpos->data;//for return
	
	plist->before->next=plist->cur->next;//set specially same place with before & cur to last element. for accessing next element successfully.
	plist->cur=plist->before;
	
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List *plist){
	return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2)){
	plist->comp=comp;//set plist's comp to comp on argument.
}
