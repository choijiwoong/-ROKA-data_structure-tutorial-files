#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void){
	BTreeNode* nd=(BTreeNode*)malloc(sizeof(BTreeNode));//get root(first) node for making tree
	nd->left=NULL;//default setting to NULL
	nd->right=NULL;
	
	return nd;//return root Node's pointer
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
