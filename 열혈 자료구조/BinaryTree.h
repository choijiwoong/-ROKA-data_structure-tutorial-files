#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode{
	BTData data;//Normal form of tree.
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);//explicitle define argument to void. it's like constructor of Binary Tree. It's will return first Node for making tree.
BTData GetData(BTreeNode* bt);//getter& setter
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);//tool for recursive.
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);//connect sub tree to main tree
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

#endif
