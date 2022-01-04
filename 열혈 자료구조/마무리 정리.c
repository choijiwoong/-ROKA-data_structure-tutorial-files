몇가지 한번 타이핑하며 접어두었던 부분들 정리하고 싶어서.. 완벽한 졸업식이랄까

	[Circular Queue]
1.	Circular Queue는 Empty와 Full state를 구별하기 위하여 한칸을 남겨두는데, Empty는 Front와 Rear이 같은 곳을 가리키고 있고, 다 찬 상태에서의 Rear.next는 Front가 되게끔 판단하면 됨! 즉, 배열의 길이가 N이라면 데이터가 N-1개 있을때가 꽉 찬 상태이다.

	[Queue based on LinkedList]
1.	Rear은 Enqueue를 담당하고, Front는 Dequeue를 담당한다. 이때 중요한 점은 연결리스트 기반 큐기 Empty state일때 Front에 NULL을 저장하는 것이다. 그러면 큐가 비었을 경우에 Rear와 Front둘 다를 고려하는 것이 아니기에 구현과 사용 모두가 편리해진다.
	이때의 장점은 노드가 하나 남았을 경우(Rear과 Front가 하나의 노드를 가리킬 경우)인데, 그 상태에서 Dequeue시 F에만 NULL을 넣고, Empty판단시 F의 NULL여부만을 판단함으로서 정의하면 문제되지 않기에 여기서 장점을 찾을 수 있다.(별다른 allocation이 없다는 가정...하에.
	만약 Rear에 NULL을 넣어야 하는 경우가 생긴다면 Dequeue과정을 둘로 나누면 된다.)
	 무튼 이러한 장점 덕분에 LinkedList기반 Queue의 Dequeue구현은 보다 간단해진다.
	 
	Data Dequeue(Queue* pq){
		Node* delNode;
		Data retData;
		
		if(QIsEmpty(pq)){
			printf("Queue Memory Error!");
			exit(-1);
		}
		delNode=pq->front;
		retData=delNode->data;
		pq->front=pq->front->next;// null저장 만약 하나남은 노드였다면 NULL값이 저장되며 QIsEmpty에서 front값만 보기에 Rear에 대한 별다른 작업이 필요하지 않다.
		
		free(delNode);
		return retData;
	}
	
	[Expression Tree]
1.	Stack을 이용해서 재귀적으로 SubTree들을 만드는데 이 과정에 대해 간략하게 다시 정리해보겠다. 우선 피연산자들은 stack으로 옮기고 연산자일 경우 stack에 쌓인 두 피연산자를 꺼내어 연산자의 자식 노드로 연결한다('1' -> '+' <- '2') 그 후 이 트리 전부를 스택으로 옮기는 과정을 반복한다
	구현은 +의 노드만 올리면 결합시 알아서 딸려올 것이다.(서브트리들이) 구현은 아래와 같다.
	
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
1.	Heap은 이진트리이되, 완전이진트리이며 모든 노드에 저장된 값이 자식 노드에 저장된 값보다 다 크거나 같은 트리이다(Root가 Manimum) 부모노드가 더 큰지 작은지에 따라 max heap, min heap으로 불린다.
2.	Heap에서의 Insert와 Delete는 순서를 고려하면서도 완전이진트리로 빈공간없이 남동쪽으로 진행해야하기에 
	새 데이터는 우선순위가 제일 낮다는 가정하에 마지막 위치에 저장한뒤 부모노드와 비교하여 조금씩 올라가며(swap) 제 자리를 찾는다(bottom to up)
	삭제는 당연히 우선순위가 높은 Root노드가 삭제 될 것이고 빈공간을 매꾸는 방법은 마지막 노드를 루트노드로 옮긴 다음에 자식 노드와의 비교를 통해서 조금씩 내려가며(swap) 제 자리를 찾는다.
3.	Heap을 기존과 마찬가지로 LinkedList와 배열로 구현할 수 있는데 배열은 우선순위가 높은 순으로 index를 1부터 할당하여 사용하는 방식이다.(index 0은 구현의 편의를 위해 사용하지 않는다. 일관된 코드진행을 위한 DummyNode같은 느낌)
	다만 기존의 Tree의 구현을 LinkedList로 한 것과는 다르게 주로 Heap은 배열을 기반으로 구현하는데, 연결리스트를 기반으로 힙을 구현하면 새 노드를 힙의 마지막 위치에 추가하는것이 쉽지 않기 때문이다. 왜냐면 마지막 노드까지 다다르기 위해 모든 노드들을 거쳐야 하기 때문이다 
	
	[MergeSort]
1.	fIdx, mid, rIdx, right로 나누어 재귀분할을 하는데, 이는 Divide And Conquer이라는 알고리즘 디자인 기법에 근거하여 만들어진 것이기에 우선적으로 병합하기 전에 분할을 먼저 한다. 우리의 경우 MergeTwoArea함수를 이용하여 MergeSort함수를 구현하였는데,
	MergeSort의 재귀적 호출 시 인자들의 조작으로 분할정렬을 먼저 하고, 그 뒤에 차례로 MergeTwoArea를 이용하여 병합을 한다. MergeSort의 구현은 아래와 같다.
	
	void MergeSort(int arr[], int left, int right){
		int mid;
		
		if(left<right){
			mid=(left+right)/2;
			
			MergeSort(arr, left, mid);
			MergeSort(arr, mid+1, right);
			
			MergeTwoArea(arr, left, mid, right);
		}
	} 
2.	MergeTwoArea의 구현은 상대적으로 길어 적진 않지만, allocation을 통해 분할된 배열들을 순서대로 추가한다음 인자로 전달된 기존의 list에 저장, free를 이용한 구현이다.
	여기서 핵심은 두 범위중 한쪽의 범위정렬이 끝났다면 다른쪽은 비교연산을 진행할 필요가 없이 그대로 붙이면 된다는 점이다. 
	
	[QuickSort]
1.	퀵정렬은 짧게 메카니즘만 말하자면 pivot을 기준으로 좌우 정렬하게 한 뒤 그 좌우 범위에 각각 pivot을 다시 둬서 재귀적으로 탐색하는 방법이다. 초기 pivot에따라 성능이 좌우되기때문에 보편적으로 3개의 값을 추출한 뒤 그 중간값을 초기 pivot으로 설정하여 성능을 극대화시킨다.

	[보간탐색]
1.	보간탐색은 발전된 이진탐색으로 단순히 mid값을 찾는 것이 아니라 index와 value의 연관성을 가정, 그 예측값으로 초기 보간탐색시작위치를 결정한다. 여기서의 index는 key, value는 value로 map즉 dictionary에서 사용이 가능하다. 
2.	다만 주의할 점은 재귀적인 탐색으로 인한 종료조건이 단순이 index(key)가 아닌 값으로 확인해야한다.

	(p.s 461p 이진 탐색 트리의 삭제 구현부에서  return dNode부분에서 right sub tree값이 null로 초기화가 안된 불안전한 부분이 있다. 그 트리들은 pointer로 이루어져있어 반환된 데이터노드의 data만을 사용하지 않고 null로 초기화되지 않은 우측 subtree를 수정하면 오류가 걷잡을 수 없이 커지기에 null로 추가적으로 리턴 전에 초기화해야한다.)

	[Rebalancing of Tree]
1.	트리의 높이는 단말 노드의 수만큼 경로가 나눠지며 그 중 가장 깊은 경로를 기준으로 높이를 알 수 있기에 재귀적으로 구성한다. 아래와 같다. 

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
1.	Linear Probing, Quadratic Probing, Double hash같은 Open Addressing Method(중복시 다른자리에 저장)와 달리 Closed Addressing Method(무슨 일이 있어도 자신의 자리에 저장한다)에 해당하는 Chaining을 사용하면 OAM에서 데이터의 이동여부를 판단하기 위해 DELETED와 EMPTY state를 위한 state정보를 Slot구조체에 표시할 필요가 없다.
2.	Chaining의 방법으로 슬롯이 연결 리스트의 노드 역활을 하게 하는 방법 & 연결 리스트의 노드와 슬롯을 구분하는 방법이 있는데 당연히 노드의 data가 slot을 가리키는 방법이 선호된다. pointer든 그 자체든 알아서 결정! 예제는 복사본 사용함. 

	[Table&Hash]
1.	typedef Person * Value;처럼 Value가 pointer형식이라고 지정해두면 NULL로 실패를 표현할 수 있으나 그것이 아니라면 NULL을 데이터 0의 반환으로 인식할 수도 있다.
	고로 NULL 포인터를 반환할 때와 별개로 탐색 실패시 return FALSE를 통해 구분하여 알려주는 것이 일반화에 좋다. (typedef *쓰면 상관 X! 이건 C언어여서 생기는 문제점!) 
	
	[Graph]
1.	그래프에서 DFS(stack for tracing)를 사용하던 BFS(queue for adding all node we can approach)를 사용하던 항상 마지막에 stack혹은 queue에서 마지막 항목까지 pop혹은 dequeue를 하여 연락의 기회를 주는것이 가장 중요하다. (끝날때 까지 끝난게 아니다! 우리가 종료한 노드에서 추가적인 연결이 있어도 작동되게끔!) 

	[MST]
1.	사이클을 형성하지 않는 그래프를 spanning tree라고 하며 트리의 일종이다.
2.	spanning tree의 모든 간선의 가중치 합이 최소인 그래프를 가리켜 최소 비용 신장 트리(minimum cost spanning tree)혹은 최소 신장 트리(minumum spanning tree)라고 한다.
3.	MST를 위한 알고리즘으로 Kruskal(내림, 오름), Prim알고리즘이 있다. Kruskal의 내림, 오름차순 정렬에 따라 간선을 하나씩 선택해나가거나 삭제해나갈 수 있다.
4.	Prim알고리즘을 간단하게 서칭하여 정리하면 개인적으로 Kruskal과 달리 정렬 없이 또다른 graph(tree)를 만들어 아무 노드 고른 뒤에 지금까지 연결된 모든 Edge중 가중치가 가장 작은 Edge들을 연결해나가는 방식이다. 사진 첨부해 두었다.

	[이상!]
1.	나 고생하셨습니다~:) 
