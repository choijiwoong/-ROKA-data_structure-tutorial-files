#ifndef __BINARY_SEARCH_TREE3_H__
#define __BINARY_SEARCH_TREE3_H__//just add Rabalance function on BinarySearchTree2

#include "BinaryTree3.h"//Use BinaryTree, add search function.

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode** pRoot);//double pointer because root node can be changed by some function. so we point root pointer's location for access rootnode regardless of refreshing.

BSTData BSTGetNodeData(BTreeNode* bst);
void BSTInsert(BTreeNode** pRoot, BSTData data);

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

void BSTShowALL(BTreeNode* bst);

#endif
