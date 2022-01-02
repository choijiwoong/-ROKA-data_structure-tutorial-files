//Just add Rabalance function on BinarySearchTree2
#include <stdio.h>

#include "BinaryTree3.h"
#include "BinarySearchTree3.h"

void BSTMakeAndInit(BTreeNode** pRoot){ *pRoot=NULL; }
BSTData BSTGetNodeData(BTreeNode* bst){ return GetData(bst); }

void BSTInsert(BTreeNode** pRoot, BSTData data){
	BTreeNode* pNode=NULL;
	BTreeNode* cNode=&pRoot;
	BTreeNode* nNode=NULL;
	
	while(cNode!=NULL){
		if(data==GetData(cNode))//ignore duplicate
			return;
		pNode=cNode;//move up to down.
		if(GetData(cNode)>data)
			cNode=GetLeftSubTree(cNode);
		else
			cNode=GetRightSubTree(cNode);
	}//now cNode==NULL, we found pNode for insertion new data(not there! to it's child)
	
	nNode=MakeBTreeNode();//new node setting
	SetData(nNode, data);
	
	if(pNode!=NULL){//check is it root node(new node we found is)
		if(data<GetData(pNode))//make proper child node.
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	} else{//if root, 
		*pRoot=nNode;//just change
	}
	
	*pRoot=Rebalance(pRoot);//***Rebalancing after all work!***_new value return because of rotate change of root node
	//not Rebalance(pRoot);
}//until here, same code with 'BinarySearchTree.h'

BTNode* BSTSearch(BTreeNode* bst, BSTData target){
	BTreeNode* nCode=bst;//current node
	BSTData cd;//current data
	
	while(cNode!=NULL){
		cd=GetData(cNode);
		
		if(target==cd)
			return cNode;
		else if(target<cd)
			cNode=GetLeftSubTree(cNode);
		else
			cNode=GetRightSubTree(cNode);
	}
	
	return NULL;//search fail
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target){
	BTreeNode* pVRoot=MakeBTreeNode();//Virtual Root node for consistent work to root node.
	BTreeNode* pNode=pVRoot;//like it
	BTreeNode* cNode=*pRoot;
	BTreeNode* dNode;
	
	ChangeRightSubTree(pVRoot, &pRoot);
	
	while(cNode!=NULL && GetData(cNode)!=target){//until fail or success
		pNode=cNode;
		if(target<GetData(cNode))
			cNode=GetLeftSubTree(cNode);
		else
			cNode=GetRightSubTree(cNode);
	}//now cNode is NULL or cNode's data is target
	//(We change upper while loop to cNode=BSTSearch(*pRoot, target), but then, we cannot change cNode's parent node to pNode.)
	
	if(cNode==NULL)//if fail, return.
		return NULL;
		
	dNode=cNode;//target
		
	if(GetLeftSubTree(dNode)==NULL && GetRightSubTree(dNode)==NULL){//target's place is terminal node
		if(GetLeftSubTree(pNode)==dNode)//just remove target
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	} else if(GetLeftSubTree(dNode)==NULL || GetRightSubTree(dNode)==NULL){//one child is exist
		BTreeNode* dcNOde;
			
		if(GetLeftSubTree(dNode)!=NULL)//get node for delete
			dcNode=GetLeftSubTree(dNode);
		else
			dcNode=GetRightSubTree(dNode);
				
		if(GetLeftSubTree(pNode)==dNode)
			ChangeLeftSubTree(pNode, dcNode);//replace dNode's place by dcNode(delete's child node)
		else
			ChangeRightSubTree(pNode, dcNode);
	} else{//two child nodes are exist_ we can replace delete node to least node in right child or Most node in left child.
		//we will choose first way. if you want, second way is also possible.
		BTreeNode* mNode=GetRightSubTree(dNode);//child_get by right
		BTreeNode* mpNode=dNode;//parent setting for consistent work
		int delData;
			
		while(GetLeftSubTree(mNode)!=NULL){//find least(no left) node_approach by left
			mp=mNode;
			mNode=GetLeftSubTree(mNode);
		}//now, mNode has least node in left that we will use for replacing. we will use mp for modifying mNode
			
		delData=GetData(dNode);//data backup because it's value will be removed.(value replace first)
		SetData(dNode, GetData(mNode));//mNode'sdata move to dNode(replace data first)
			
		if(GetLeftSubTree(mpNode)==mNode)//if mNode is in left of mpNode_��ü����� parent��� ���󿬰� 
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));//np's left ro mNode's right node.
			//(���� ã�� mNode�� left���� NULL�� �� ����������κ��� ���� ����Ʈ���� �������� ã�������� �� ��ü����� 
			//��������Ʈ���� ���� ���� �ƴϴϱ� �װ��� ������ dNode�ڸ��� �����Ͽ� dNode��������Ʈ�� �츮�� dNode����.) 
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
				
		dNode=mNode;//deallocated address of mNode to dNode._***����***. ���� dNode��ü�� mNode�� ġȯ�ع����� mNode�� ���� ��������� NULL, ������ �״�� �ƴѰ�? �ܼ��� �ڿ� ��Ȱ�붧���� �� �ּҸ� �����Ѱǰ� 
		SetData(dNode, delData);//set data for return_������ �ڿ��� ����ѰŶ� �Ϸ��� �µ����� ���� �ƴ϶� ��忬�ᵵ ������Ѿ��ϴµ� 
		//�ذ�?! �������� ���� �� ������ ���� if Change�ο��� �ϼ��Ǿ���, �ڿ� ��Ȱ���Ͽ� ������ ��带 ������ ��������
		//dNode�� mNode�ּҰ��� ����. mNode�� �̹� dNode��ġ�� ������ ����, ����Ǿ� �����������. ��� Setdata�� ������ �ִ� dNode�� �����͸� �����Ͽ� 
		//�߰����� malloc, free���� mNode�ּҰ��� ���� mNode�� ��ȯ. ��, mNode�� left, right�� �������� ���� ����Ű�� �ְ� pointer�̱⿡ �������� �ʱ⿡ ����ڴ� data���� ����ؾ��Ѵ�. 
		dNode.right=NULL;//��� �����Ͽ� �߰�. left�� �̹� NULL 
	}
		
		if(GetRightSubTree(pVRoot)!=*pRoot)//if root node is changed
			*pRoot=GetRightSubTree(pVRoot);//refresh root node
		
		free(pVRoot);
		*pRoot=Rebalance(pRoot);//***Rebalancing after all work!*** not Rebalance(pRoot);
		return dNode;
}

void ShowIntData(int data){ printf("%d ", data); }
void BSTShowAll(BTreeNode* bst){ INorderTraverse(bst, ShowIntData); }

#endif
