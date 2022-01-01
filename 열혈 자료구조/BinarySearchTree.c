#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode** pRoot){
	*pRoot=NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst){
	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data){
	BTreeNode* pNode=NULL;//parent node of current node.
	BTreeNode* cNode=&pRoot;//current node
	BTreeNode* nNode=NULL;//for use new node
	
	while(cNode!=NULL){
		if(data==GetData(cNode))//donot allow duplication. escape without insertion
			return;
			
		pNode=cNode;
		if(GetData(cNode)>data)
			cNode=GetLeftSubTree(cNode);
		else
			cNode=GetRightSubTree(cNode);
	}//now, cNode is NULL, parent is exist. get child Node that we can insert new node
	
	nNode=MakeBTreeNoce();//make new node
	SetData(nNode, data);
	
	if(pNode!=NULL){//parent is existing
		if(data<GetData(pNode))//insert by value of parent. decide left or right
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	} else{//if root_찾은 최적의 위치가 처음부터 컷되서 루트에 들어가야 한다면(빈 트리) 
		*pRoot=nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target){
	BTreeNode* nCode=bst;//current node
	BSTData cd;//current data
	
	while(cNode!=NULL){
		cd=GetData(cNode);
		
		if(target==cd)
			return cNode;
		else if(target<cd)
			cNode=GetLeftSubTree(cNode);
		else
			cNode=GetRightSubTree(cNode);
	}
	
	return NULL;//search fail
}
