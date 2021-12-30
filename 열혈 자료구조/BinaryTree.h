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

void DeleteTree(BTreeNode* bt);

//BinaryTree2's content
typedef void (*VisitFuncPtr)(BTData data);//work function for each node. like printNode that will be used by BinaryTree2's user.
//일반적으로 함수포인터를 사용하려면 int (*func)(int, double) 처럼 자료형과 이름이 혼합될 뿐더러 같은 반환형&인자를 가지는 함수포인터에 대해 매번 정보를 입력해야한다면
//typedef를 사용하여 하나의 타입으로서 자주쓰이는 형식을 가지는 함수포인터로 정의하면 실제 자료형처럼 보다 편하게 함수 포인터를 사용할 수 있다. 
//Like argument of Traverse functions.

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);//Tool for Traverse
void InorderTraversae(BTreeNode* bt, VisitFuncPtr action);
void PostOrderTraverse(BTreeNode* bt, VisitFuncPtr action);

#endif
