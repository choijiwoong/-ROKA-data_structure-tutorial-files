��� �ѹ� Ÿ�����ϸ� ����ξ��� �κе� �����ϰ� �;.. �Ϻ��� �������̶���

	[Circular Queue]
1.	Circular Queue�� Empty�� Full state�� �����ϱ� ���Ͽ� ��ĭ�� ���ܵδµ�, Empty�� Front�� Rear�� ���� ���� ����Ű�� �ְ�, �� �� ���¿����� Rear.next�� Front�� �ǰԲ� �Ǵ��ϸ� ��! ��, �迭�� ���̰� N�̶�� �����Ͱ� N-1�� �������� �� �� �����̴�.

	[Queue based on LinkedList]
1.	Rear�� Enqueue�� ����ϰ�, Front�� Dequeue�� ����Ѵ�. �̶� �߿��� ���� ���Ḯ��Ʈ ��� ť�� Empty state�϶� Front�� NULL�� �����ϴ� ���̴�. �׷��� ť�� ����� ��쿡 Rear�� Front�� �ٸ� ����ϴ� ���� �ƴϱ⿡ ������ ��� ��ΰ� ��������.
	�̶��� ������ ��尡 �ϳ� ������ ���(Rear�� Front�� �ϳ��� ��带 ����ų ���)�ε�, �� ���¿��� Dequeue�� F���� NULL�� �ְ�, Empty�Ǵܽ� F�� NULL���θ��� �Ǵ������μ� �����ϸ� �������� �ʱ⿡ ���⼭ ������ ã�� �� �ִ�.(���ٸ� allocation�� ���ٴ� ����...�Ͽ�.
	���� Rear�� NULL�� �־�� �ϴ� ��찡 ����ٸ� Dequeue������ �ѷ� ������ �ȴ�.)
	 ��ư �̷��� ���� ���п� LinkedList��� Queue�� Dequeue������ ���� ����������.
	 
	Data Dequeue(Queue* pq){
		Node* delNode;
		Data retData;
		
		if(QIsEmpty(pq)){
			printf("Queue Memory Error!");
			exit(-1);
		}
		delNode=pq->front;
		retData=delNode->data;
		pq->front=pq->front->next;// null���� ���� �ϳ����� ��忴�ٸ� NULL���� ����Ǹ� QIsEmpty���� front���� ���⿡ Rear�� ���� ���ٸ� �۾��� �ʿ����� �ʴ�.
		
		free(delNode);
		return retData;
	}
	
	[Expression Tree]
1.	Stack�� �̿��ؼ� ��������� SubTree���� ����µ� �� ������ ���� �����ϰ� �ٽ� �����غ��ڴ�. �켱 �ǿ����ڵ��� stack���� �ű�� �������� ��� stack�� ���� �� �ǿ����ڸ� ������ �������� �ڽ� ���� �����Ѵ�('1' -> '+' <- '2') �� �� �� Ʈ�� ���θ� �������� �ű�� ������ �ݺ��Ѵ�
	������ +�� ��常 �ø��� ���ս� �˾Ƽ� ������ ���̴�.(����Ʈ������) ������ �Ʒ��� ����.
	
	BTreeNode* MakeExpTree(char exp[]){
		Stack stack;
		BTreeNode* pnode;
		
		int expLen=strlen(exp);
		int i;
		StackInit(&stack);
		
		for(i=0; i<expLen; i++){
			pnode=MakeBTreeNode();
			
			if(isdigit(exp[i])){
				SetData(pnode, exp[i]-'0');
			} else{
				MakeRightSubTree(pnode, SPop(&stack));
				MakeLeftSubTree(pnode, SPop(&stack));
				SetData(pnode, exp[i]);
			}
			
			SPush(&stack, pnode);
		}
		
		return SPop(&stack);
	}
	
	[Heap]
1.	Heap�� ����Ʈ���̵�, ��������Ʈ���̸� ��� ��忡 ����� ���� �ڽ� ��忡 ����� ������ �� ũ�ų� ���� Ʈ���̴�(Root�� Manimum) �θ��尡 �� ū�� �������� ���� max heap, min heap���� �Ҹ���.
2.	Heap������ Insert�� Delete�� ������ ����ϸ鼭�� ��������Ʈ���� ��������� ���������� �����ؾ��ϱ⿡ 
	�� �����ʹ� �켱������ ���� ���ٴ� �����Ͽ� ������ ��ġ�� �����ѵ� �θ���� ���Ͽ� ���ݾ� �ö󰡸�(swap) �� �ڸ��� ã�´�(bottom to up)
	������ �翬�� �켱������ ���� Root��尡 ���� �� ���̰� ������� �Ųٴ� ����� ������ ��带 ��Ʈ���� �ű� ������ �ڽ� ������ �񱳸� ���ؼ� ���ݾ� ��������(swap) �� �ڸ��� ã�´�.
3.	Heap�� ������ ���������� LinkedList�� �迭�� ������ �� �ִµ� �迭�� �켱������ ���� ������ index�� 1���� �Ҵ��Ͽ� ����ϴ� ����̴�.(index 0�� ������ ���Ǹ� ���� ������� �ʴ´�. �ϰ��� �ڵ������� ���� DummyNode���� ����)
	�ٸ� ������ Tree�� ������ LinkedList�� �� �Ͱ��� �ٸ��� �ַ� Heap�� �迭�� ������� �����ϴµ�, ���Ḯ��Ʈ�� ������� ���� �����ϸ� �� ��带 ���� ������ ��ġ�� �߰��ϴ°��� ���� �ʱ� �����̴�. �ֳĸ� ������ ������ �ٴٸ��� ���� ��� ������ ���ľ� �ϱ� �����̴� 
	
	[MergeSort]
1.	fIdx, mid, rIdx, right�� ������ ��ͺ����� �ϴµ�, �̴� Divide And Conquer�̶�� �˰��� ������ ����� �ٰ��Ͽ� ������� ���̱⿡ �켱������ �����ϱ� ���� ������ ���� �Ѵ�. �츮�� ��� MergeTwoArea�Լ��� �̿��Ͽ� MergeSort�Լ��� �����Ͽ��µ�,
	MergeSort�� ����� ȣ�� �� ���ڵ��� �������� ���������� ���� �ϰ�, �� �ڿ� ���ʷ� MergeTwoArea�� �̿��Ͽ� ������ �Ѵ�. MergeSort�� ������ �Ʒ��� ����.
	
	void MergeSort(int arr[], int left, int right){
		int mid;
		
		if(left<right){
			mid=(left+right)/2;
			
			MergeSort(arr, left, mid);
			MergeSort(arr, mid+1, right);
			
			MergeTwoArea(arr, left, mid, right);
		}
	} 
2.	MergeTwoArea�� ������ ��������� ��� ���� ������, allocation�� ���� ���ҵ� �迭���� ������� �߰��Ѵ��� ���ڷ� ���޵� ������ list�� ����, free�� �̿��� �����̴�.
	���⼭ �ٽ��� �� ������ ������ ���������� �����ٸ� �ٸ����� �񱳿����� ������ �ʿ䰡 ���� �״�� ���̸� �ȴٴ� ���̴�. 
	
	[QuickSort]
1.	�������� ª�� ��ī���� �����ڸ� pivot�� �������� �¿� �����ϰ� �� �� �� �¿� ������ ���� pivot�� �ٽ� �ּ� ��������� Ž���ϴ� ����̴�. �ʱ� pivot������ ������ �¿�Ǳ⶧���� ���������� 3���� ���� ������ �� �� �߰����� �ʱ� pivot���� �����Ͽ� ������ �ش�ȭ��Ų��.

	[����Ž��]
1.	����Ž���� ������ ����Ž������ �ܼ��� mid���� ã�� ���� �ƴ϶� index�� value�� �������� ����, �� ���������� �ʱ� ����Ž��������ġ�� �����Ѵ�. ���⼭�� index�� key, value�� value�� map�� dictionary���� ����� �����ϴ�. 
2.	�ٸ� ������ ���� ������� Ž������ ���� ���������� �ܼ��� index(key)�� �ƴ� ������ Ȯ���ؾ��Ѵ�.

	(p.s 461p ���� Ž�� Ʈ���� ���� �����ο���  return dNode�κп��� right sub tree���� null�� �ʱ�ȭ�� �ȵ� �Ҿ����� �κ��� �ִ�. �� Ʈ������ pointer�� �̷�����־� ��ȯ�� �����ͳ���� data���� ������� �ʰ� null�� �ʱ�ȭ���� ���� ���� subtree�� �����ϸ� ������ ������ �� ���� Ŀ���⿡ null�� �߰������� ���� ���� �ʱ�ȭ�ؾ��Ѵ�.)

	[Rebalancing of Tree]
1.	Ʈ���� ���̴� �ܸ� ����� ����ŭ ��ΰ� �������� �� �� ���� ���� ��θ� �������� ���̸� �� �� �ֱ⿡ ��������� �����Ѵ�. �Ʒ��� ����. 

	int GetHeightDiff(BTreeNode* bst){
		int lsh;
		int rsh;
		
		if(bst==NULL)
			return 0;
		
		lsh=GetHeight(GetLeftSubTree(bst));
		rsh=GetHeight(GetRightSubTree(bst));
		return lsh-rsh;//return balance const
	}
	
	[Hash Collision]
1.	Linear Probing, Quadratic Probing, Double hash���� Open Addressing Method(�ߺ��� �ٸ��ڸ��� ����)�� �޸� Closed Addressing Method(���� ���� �־ �ڽ��� �ڸ��� �����Ѵ�)�� �ش��ϴ� Chaining�� ����ϸ� OAM���� �������� �̵����θ� �Ǵ��ϱ� ���� DELETED�� EMPTY state�� ���� state������ Slot����ü�� ǥ���� �ʿ䰡 ����.
2.	Chaining�� ������� ������ ���� ����Ʈ�� ��� ��Ȱ�� �ϰ� �ϴ� ��� & ���� ����Ʈ�� ���� ������ �����ϴ� ����� �ִµ� �翬�� ����� data�� slot�� ����Ű�� ����� ��ȣ�ȴ�. pointer�� �� ��ü�� �˾Ƽ� ����! ������ ���纻 �����. 

	[Table&Hash]
1.	typedef Person * Value;ó�� Value�� pointer�����̶�� �����صθ� NULL�� ���и� ǥ���� �� ������ �װ��� �ƴ϶�� NULL�� ������ 0�� ��ȯ���� �ν��� ���� �ִ�.
	��� NULL �����͸� ��ȯ�� ���� ������ Ž�� ���н� return FALSE�� ���� �����Ͽ� �˷��ִ� ���� �Ϲ�ȭ�� ����. (typedef *���� ��� X! �̰� C���� ����� ������!) 
	
	[Graph]
1.	�׷������� DFS(stack for tracing)�� ����ϴ� BFS(queue for adding all node we can approach)�� ����ϴ� �׻� �������� stackȤ�� queue���� ������ �׸���� popȤ�� dequeue�� �Ͽ� ������ ��ȸ�� �ִ°��� ���� �߿��ϴ�. (������ ���� ������ �ƴϴ�! �츮�� ������ ��忡�� �߰����� ������ �־ �۵��ǰԲ�!) 

	[MST]
1.	����Ŭ�� �������� �ʴ� �׷����� spanning tree��� �ϸ� Ʈ���� �����̴�.
2.	spanning tree�� ��� ������ ����ġ ���� �ּ��� �׷����� ������ �ּ� ��� ���� Ʈ��(minimum cost spanning tree)Ȥ�� �ּ� ���� Ʈ��(minumum spanning tree)��� �Ѵ�.
3.	MST�� ���� �˰������� Kruskal(����, ����), Prim�˰����� �ִ�. Kruskal�� ����, �������� ���Ŀ� ���� ������ �ϳ��� �����س����ų� �����س��� �� �ִ�.
4.	Prim�˰����� �����ϰ� ��Ī�Ͽ� �����ϸ� ���������� Kruskal�� �޸� ���� ���� �Ǵٸ� graph(tree)�� ����� �ƹ� ��� �� �ڿ� ���ݱ��� ����� ��� Edge�� ����ġ�� ���� ���� Edge���� �����س����� ����̴�. ���� ÷���� �ξ���.

	[�̻�!]
1.	�� ����ϼ̽��ϴ�~:) 
