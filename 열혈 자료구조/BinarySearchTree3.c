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
			
		if(GetLeftSubTree(mpNode)==mNode)//if mNode is in left of mpNode_대체노드의 parent노드 정상연결 
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));//np's left ro mNode's right node.
			//(지금 찾은 mNode가 left값이 NULL인 즉 삭제대상으로부터 우측 서브트리중 최저값을 찾은것이지 그 대체대상의 
			//우측서브트리가 없는 것은 아니니까 그것을 기존의 dNode자리에 연결하여 dNode우측서브트리 살리고 dNode삭제.) 
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
				
		dNode=mNode;//deallocated address of mNode to dNode._***문제***. 현재 dNode자체를 mNode로 치환해버리면 mNode의 현재 좌측서브는 NULL, 우측은 그대로 아닌가? 단순히 자원 재활용때문에 그 주소를 대입한건가 
		SetData(dNode, delData);//set data for return_하지만 자원만 사용한거라 하려면 셋데이터 뿐이 아니라 노드연결도 변경시켜야하는데 
		//해결?! 실질적인 삭제 및 연결은 위의 if Change부에서 완성되었고, 자원 재활용하여 삭제된 노드를 리턴할 목적으로
		//dNode에 mNode주소값을 삽입. mNode는 이미 dNode위치로 데이터 복사, 연결되어 쓸모없어졌음. 고로 Setdata로 기존에 있던 dNode의 데이터를 갖게하여 
		//추가적인 malloc, free없이 mNode주소값을 가진 mNode를 반환. 단, mNode의 left, right는 쓸데없는 값을 가리키고 있고 pointer이기에 안전하지 않기에 사용자는 data만을 사용해야한다. 
		dNode.right=NULL;//고로 수정하여 추가. left는 이미 NULL 
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
