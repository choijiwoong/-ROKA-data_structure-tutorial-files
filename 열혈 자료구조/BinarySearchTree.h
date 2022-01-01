#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode** pRoot);//root to double pointer
BSTData BSTGetNodeData(BTreeNode* bst);
void BSTInsert(BTreeNode** pRoot, BSTData data);//root can be changed. so use **
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

#endif 
