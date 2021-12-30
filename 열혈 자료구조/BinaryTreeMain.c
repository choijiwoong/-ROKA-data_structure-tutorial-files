#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main(){
	/*1. use it without traversal
	BTreeNode* bt1=MakeBTreeNode();
	BTreeNode* bt2=MakeBTreeNode();
	BTreeNode* bt3=MakeBTreeNode();
	BTreeNode* bt4=MakeBTreeNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);//Complete Binary Tree! But not Full Binary Tree!
	
	printf("%d \n", GetData(GetLeftSubTree(bt1)));//bt1's left child node
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));//approach without recursive Traversal.	
	*/
	
	//2. use it with traversal
	BTreeNode* bt1=MakeBTreeNode();//allocation
	BTreeNode* bt2=MakeBTreeNode();
	BTreeNode* bt3=MakeBTreeNode();
	BTreeNode* bt4=MakeBTreeNode();
	BTreeNode* bt5=MakeBTreeNode();
	BTreeNode* bt6=MakeBTreeNode();
	
	SetData(bt1, 1); SetData(bt2, 2);//set data
	SetData(bt3, 3); SetData(bt4, 4);
	SetData(bt5, 5); SetData(bt6, 6);
	
	MakeLeftSubTree(bt1, bt2);//make tree relation
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);
	
	//Approach by Traversal
	PreorderTraverse(bt1, ShowIntData);
	printf("\n");
	
	InorderTraverse(bt1, ShowIntData);
	printf("\n");
	
	PostorderTraverse(bt1, ShowIntData);
	printf("\n");
	
	//Delete recursively
	DeleteTree(bt1);
	
	return 0;
}
