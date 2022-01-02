//BinaryTree에 추가해서 표현하려했는데 주석도 바꿔야하고 겸사겸사 정리 느낌으로 최종 BinaryTree3
#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

typedef int BTData;

typedef struct _bTreeNode{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);//return initial BTreeNode*
BTData GetData(BTreeNode* bt);//getter
void SetData(BTreeNode* bt, BTData data);//setter

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);//with free
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void (*VisitFuncPtr)(BTData data);//for action foreach elements

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);//for traverse
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);//without free. return
BTreeNode* RemoveRightSubTree(BTreeNode* bt);
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);//just change
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

#endif
