#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void){
	BTreeNode* nd=(BTreeNode*)malloc(sizeof(BTreeNode));//get node for making tree. (not only root node)
	nd->left=NULL;//default setting to NULL
	nd->right=NULL;
	
	return nd;//return Node's pointer
}

BTData GetData(BTreeNode* bt){
	return bt->data;
}
void SetData(BTreeNode* bt, BTData data){
	bt->data=data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt){
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt){
	return bt->right;
}

void MakeLeftSubTree(BTree* main, BTreeNode* sub){
	if(main->left!=NULL)//remove initial data for cover with free
		free(main->left);//not only one node! but whole node by recursive approach. BY TRAVERSAL
	
	main->left=sub;//set by left
}
void MakeRightDubTree(BTreeNode* main, BTreeNode* sub){
	if(main->right!=NULL)
		free(main->right);
	
	main->right=sub;
}

//For Delete
void DeleteTree(BTree* bt){
	if(bt==NULL)//recursive approach. we will use PostorderTraversal for free all node
		return;
		
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("del tree data: %d\n", bt->data);
	free(bt);
}

//For Traverse 
//Sequence of handling data & call recursively defines sort of Traversal(Preorder, Inorder, Postorder)
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action){
	if(bt==NULL)//for stop action functor
		return;
	
	action(bt->data);//do work first
	PreorderTraverse(bt->left, action);//rescursive!
	PreorderTraverse(bt->right, action);
}
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action){
	if(bt==NULL)
		return;
		
	InorderTraverse(bt->left, action);
	action(bt->data);//do work middle
	InorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action){
	if(bt==NULL)
		return;
		
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);//do work last
}
