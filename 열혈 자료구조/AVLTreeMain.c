#include <stdio.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"

int main(){
	BTreeNode* avlRoot;
	BTreeNode* clNode;
	BTreeNode* crNode;
	BSTMakeAndInit(&avlRoot);
	
	for(int i=1; i<10; i++)
		BSTInsert(&avlRoot, i);
	BSTInsert(&avlRoot, 13); BSTInsert(&avlRoot, 10); BSTInsert(&avlRoot, 12);//for check LR handling
	BSTInsert(&avlRoot, 15); BSTInsert(&avlRoot, 19); BSTInsert(&avlRoot, 17);//for check RL handling
	
	printf("Root node: %d \n", GetData(avlRoot));
	
	clNode=GetLeftSubTree(avlRoot);
	crNode=GetRightSubTree(avlRoot);
	printf("left1: %d, right1: %d\n", GetData(clNode), GetData(crNode));
	
	clNode=GetLeftSubTree(clNode);
	crNode=GetRightSubTree(crNode);
	printf("left2: %d, right2: %d\n", GetData(clNode), GetData(crNode));
	
	clNode=GetLeftSubTree(clNode);
	crNode=GetRightSubTree(crNode);
	printf("left3: %d, right3: %d\n", GetData(clNode), GetData(crNode));
	
	clNode=GetLeftSubTree(clNode);
	crNode=GetRightSubTree(crNode);
	printf("left4: %d, right4: %d\n", GetData(clNode), GetData(crNode));
	
	return 0;
}
