#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"//for calculation
#include "BinaryTree.h"

BTreeNode* MakeExpTree(char exp[]){
	Stack stack;
	BTreeNode* pnode;
	
	int explen=strlen(exp);//get length of expression
	int i;//for for loop
	
	StackInit(&stack);//initialization of stack
	
	for(i=0; i<expLen; i++){//for each element of expression
		pnode=MakeBTreeNode();//make node for handling data easily
		
		if(isdigit(exp[i])){//if number, push directly to stack
			SetData(pnode, exp[i]-'0');
		}else{//if operator, 
			MakeRightSubTree(pnode, SPop(&stack));//make subtree for operand with order of calculation(direction)
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);//set one pair of tree to pnode
		}
		
		SPush(&stack, pnode);//push to stack. (Not recursive But like recursive becauseof speciality of node)
	}
	
	return SPop(&stack);//return Connected Node with operator & operand(BTreeNode*)
}

int EvaluateExpTree(BTreeNode* bt){//calculation of expression tree
	int op1, op2;
	
	if(GetLeftSubTree(bt)==NULL && GetRightSubTree(bt)==NULL)//if terminal tree
		return GetData(bt);//return data(for stop too)
		
	op1=EvaluateExpTree(GetLeftSubTree(bt));//recursive! any way get data of termial node(it can be already calculated node)
	op2=EvaluateExpTree(GetRightSubTree(bt));
	
	switch(GetData(bt)){
		case '+'://do operation by operator with operand that will be saved in op1 & op2
			return op1+op2;
		case '-':
			return op1-op2;
		case '*':
			return op1*op2;
		case '/':
			return op1/op2;
	}
	
	return 0;//welldone
}

void ShowNodeData(int data){//functor for Traverse. In Traverse function, it will call this by using node's data automatically. ont on pointer of node directly.
	//Why type is int? why not BTData?
	if(0<=data && data<=9)//we suppose number has one space.
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt){//tools only for show
	//PreorderTraverse(bt, ShowNodeData);
	if(bt==NULL)
		return;
		
	if(bt->left!=NULL || bt->right!=NULL)
		printf("(");
	
	ShowNodeData(bt->data);
	ShowPrefixTypeExp(bt->left);
	ShowPrefixTypeExp(bt->right);
	
	if(bt->left!=NULL || bt->right!=NULL)
		printf(")");
}
void ShowInfixTypeExp(BTreeNode* bt){//make it consider bracket!
	//InorderTraverse(bt, ShowNodeData);//previous version_without bracket.
	if(bt==NULL)
		return;
	
	if(bt->left!=NULL || bt->right!=NULL)//중위표기법을 이용하여 표기하는데, 연산자의 수와 소괄호 한 쌍의 수가 일치하기에 구현이 보다 편리하다. 
		printf(" ( ");
		
	ShowInfixTypeExp(bt->left);//recursive. operand1
	ShowNodeData(bt->data);//operation
	ShowInfixTypeExp(bt->right);//operand2?
	
	if(bt->left!=NULL || bt->right!=NULL)
		printf(" ) ");
}
void ShowPostfixTypeExp(BTreeNode* bt){
	//PostorderTraverse(bt, ShowNodeData);
	if(bt==NULL)
		return;
		
	if(bt->left!=NULL || bt->right!=NULL)
		printf(" ( ");
		
	ShowPostfixTypeExp(bt->left);
	ShowPostfixTypeExp(bt->right);
	ShowNodeData(bt->data);
	
	if(bt->left!=NULL || bt->right!=NULL)
		printf(")");
}
