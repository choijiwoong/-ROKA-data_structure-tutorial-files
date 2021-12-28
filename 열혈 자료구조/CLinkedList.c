#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List *plist){//initialiation
	plist->tail=NULL;
	plist->cur=NULL;
	plist->before=NULL;
	plist->numOfData=0;
}

void LInsertFront(List *plist, Data data){//insert front
	Node *newNode=(NOde*)malloc(sizeof(Node));
	
	if(plist->tail==NULL){//if first element insert, connect itself & tail to newNode
		plist->tail=newNode;
		newNode->next=newNode;
	} else{//if Dummy node exist, we don't have to use if condition.
		newNode->next=plist->tail->next;//connect to first element
		plist->tail->next=newNode;
	}
	
	(plist->numOfData)++;
}

void LInsert(List *plist, Data data){//insert last. it's simmilar with LInsertFront. just added tail location.
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	
	if(plist->tail==NULL){
		plist->tail=newNode;
		newNode->next=newNode;
	} else{
		newNode->next=plist->tail->next;
		plist->tail->next=newNode;
		plist->tail=newNode;//Only one ifference with LInsertFront
	}
	
	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata){
	if(plist->tail==NULL)
		return FALSE;
	
	plist->before=plist->tail;
	plist->cur=plist->tail->next;//before, cur setting
	
	*pdata=plist->cur->data;//approach by using cur
	return TRUE;
}

int LNext(List *plist, Data *pdata){
	if(plist->tail==NULL)
		return FALSE;
		
	plist->before=plist->cur;
	plist->cur=plist->cur->next;
	
	*pdata=plist->cur->data;
	return TRUE;
}

Data LRemove(List *plist){//remove cur
	Node *rpos=plist->cur;//for delete(free)
	Data rdata=rpos->data;//for return value
	
	if(rpos==plist->tail){//if it's tail data. we have to do extra handling that moves location of tail.
		if(plist->tail==plist->tail->next)//only one data is exist, set tail NULL
			plist->tail=NULL;
		else//just reset tail.
			plist->tail=plist->before;
	}
	
	plist->before->next=plist->cur->next;
	plist->cur=plist->before;//before, cur setting
	
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List *plist){
	return plist->numOfData;
}
