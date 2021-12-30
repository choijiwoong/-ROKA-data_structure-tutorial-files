#include <stdio.h>
#include "ExpressionTree.h"

int main(){
	char exp[]="12+7";
	BTreeNode* eTree=MakeExpTree(exp);
	
	printf("expression on Preorder: ");
	ShowPrefixTypeExp(eTree);
	printf("\n");
	
	printf("expression on Inorder: ");
	ShowInfixTypeExp(eTree);
	printf("\n");
	
	printf("expression on Postorder: ");
	ShowPostfixTypeExp(eTree);
	printf("\n");
	
	return 0;
}
