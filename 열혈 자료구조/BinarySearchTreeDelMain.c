#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree2.h"

int main(){
	BTreeNode* bstRoot;
	BTreeNode* sNode;
	BSTMakeAndInit(&bstRoot);
	
	BSTInsert(&bstRoot, 5); BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1); BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4); BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3); BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);
	
	BSTShowAll(bstRoot); printf("\n");//show all
	sNode=BSTRemove(&bstRoot, 8);//delete by data
	free(sNode);
	
	BSTShowAll(bstRoot); printf("\n");//show all
	sNode=BSTRemove(&bstRoot, 1);//delete by data
	free(sNode);
	
	BSTShowAll(bstRoot); printf("\n");//show all
	sNode=BSTRemove(&bstRoot, 6);//delete by data
	free(sNode);
	
	BSTShowAll(bstRoot); printf("\n");
	
	return 0;
}
