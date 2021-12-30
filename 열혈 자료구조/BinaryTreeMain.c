#include <stdio.h>
#include "BinaryTree.h"

int main(){
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
	
	return 0;
}
