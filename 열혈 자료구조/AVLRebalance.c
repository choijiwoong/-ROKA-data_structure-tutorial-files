#include <stdio.h>
#include "BinaryTree3.h"//BinarySearchTree2+rebalancing=AVLTree. this AVLRebalance.c & AVLRebalance.h is just tool for rebalancing
//We just add rebalancing function after BinarySearchTree's Insert, Remove

//use BinaryTree3
BTreeNode* RotateLL(BTreeNode* bst){
	BTreeNode* pNode;
	BTreeNode* cNode;
	
	pNode=bst;//parent
	cNode=GetLeftSubTree(pNode);//child
	
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));////move T3. move subTree of cNode (that's place will be replaced by other node_pNode)
	ChangeRightSubTree(cNode, pNode);//make cNode's right subTree to pNode.
	
	return cNode;//root is changed to cNode
}
BTreeNode* RotateRR(BTreeNode* bst){
	BTreeNode* pNode;
	BTreeNode* cNode;
	
	pNode=bst;//parent child set
	cNode=GetRightSubTree(pNode);
	
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode);//move cNode's left to proper location(cNode's Left->pNode's right)
	ChangeLeftSubTree(cNode, pNode);//cNode's left set to pNode
	
	return cNode;
}

BTreeNode* RotateLR(BTreeNode* bst){
	BTreeNode* pNode;
	BTreeNode* cNode;
	
	pNode=bst;//setting
	cNode=GetLeftSubTree(pNode);
	
	ChangeLeftSubTree(pNode, RotateRR(cNode));//partly(cNode as root node) RR & set pNode's Left(refresh)
	return RotateLL(pNode);//return result of LL rotate on pNode
}
BTreeNode* RotateRL(BTreeNode* bst){//change to LL state, and apply RotateLL
	BTreeNode* pNode;
	BTreeNode* cNode;
	
	pNode=bst;
	cNode=GetRightSubTree(pNode);
	
	ChangeRightSubTree(pNode, RotateLL(cNode));
	return RotateRR(pNode);
}

int GetHeight(BTreeNode* bst){
	int leftH;
	int rightH;
	
	if(bst==NULL)//stop condition
		return 0;//no height
	
	leftH=GetHeight(GetLeftSubTree(bst));//use recursive for calculation regardless of height of sub tree.
	rightH=GetHeight(GetRightSubTree(bst));
	
	if(leftH>rightH)//1(true)>0
		return leftH+1;//++ when call. this function calls as much as subtree.
	else
		return rightH+1;
}
int GetHeightDiff(BTreeNode* bst){
	int lsh;
	int rsh;
	
	if(bst==NULL)
		return 0;
		
	lsh=GetHeight(GetLeftSubTree(bst));
	rsg=GetHeight(GetRightSubTree(bst));
	return lst-rsh;
}


BTreeNode* Rebalance(BTreeNode** pRoot){//Real rebalancing by upper tools
	int hDiff=GetHeightDiff(*pRoot);//calculate balance const(±ÕÇüÀÎ¼ö)
	
	if(hDiff>1){//check by abs
		if(GetHeightDiff(GetLeftSubTree(*pRoot))>0)
			*pRoot=RotateLL(*pRoot);
		else
			*pRoot=RotateLR(*pRoot);
	}else if(hdiff<-1){
		if(GetHeightDiff(GetRightSubTree(*pRoot))<0)
			*pRoot=RotateRR(*pRoot);
		else
			*pRoot=RotateRL(*pRoot);
	}
	
	return *pRoot;
}
