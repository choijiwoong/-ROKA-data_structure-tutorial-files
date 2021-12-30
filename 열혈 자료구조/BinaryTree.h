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
//�Ϲ������� �Լ������͸� ����Ϸ��� int (*func)(int, double) ó�� �ڷ����� �̸��� ȥ�յ� �Ӵ��� ���� ��ȯ��&���ڸ� ������ �Լ������Ϳ� ���� �Ź� ������ �Է��ؾ��Ѵٸ�
//typedef�� ����Ͽ� �ϳ��� Ÿ�����μ� ���־��̴� ������ ������ �Լ������ͷ� �����ϸ� ���� �ڷ���ó�� ���� ���ϰ� �Լ� �����͸� ����� �� �ִ�. 
//Like argument of Traverse functions.

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);//Tool for Traverse
void InorderTraversae(BTreeNode* bt, VisitFuncPtr action);
void PostOrderTraverse(BTreeNode* bt, VisitFuncPtr action);

#endif
