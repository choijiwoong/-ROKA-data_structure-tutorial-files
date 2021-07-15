#단일 링크드 리스트
class SLinkedList:

    #S_L_list에서 쓸 노드
    class Node:
        def __init__(self, v, n=None):
            self.value=v#저장된 데이터
            self.next=n#다음 노드를 가리키는 변수

    #S_L_list에서 필요한 변수
    def __init__(self):
        self.head=None #첫 생성 시 내부에는 노드가 없음


    #삽입
    def insertNode(self, v):#추가할 데이터
        #만일 처음 노드의 경우 head가 None
        if self.head is None:
            #head에 새 노드를 저장
            self.head=self.Node(v)

        else: #이미 노드가 존재
            #head에 새 노드 저장, 기존 head의 노드는 새로 생성할 노드의 next로 저장
            self.head=self.Node(v,self.head)


    #출력
    def printNode(self):
        #데이터가 없다면
        if self.head is None:
            print("저장된 데이터가 없음")
            return
        else:
            print("<현재 리스트 구조>",end='\t')#print마지막 개행을 변경
            link=self.head#처음은 head를 지정. 이후에는 현 노드의 next지정

            #link가 가리키는 노드가 없을 때까지 반복
            #none, 0, ""은 조건판단에서 false처리, 그 외는 True처리
            while link:
                print(link.value,'->',end=' ')
                link=link.next
            print()

    #삭제
    def deleteNode(self):
        #노드가 없으면 skip
        if self.head is None:
            print("삭제할 노드가 없습니다.")
            return
        else:
            #head를 현 head의 next, 즉 다음 노드로 변경.
            self.head=self.head.next

    #탐색
    def searchNode(self, v):
        #데이터가 없을 때
        if self.head is None:
            print("저장된 데이터가 없음.")
            return
        else:
            link=self.head#처음은 head를 지정, 이후부터는 현 노드의 next를 지정
            index=0#몇번째 노드
            while link:
                #내가 찾는 노드인가
                if v==link.value:
                    return index
                else:
                    link=link.next
                    index+=1

#테스트
if __name__=="__main__":
    sl = SLinkedList()
    sl.insertNode('1st')
    sl.insertNode('2nd')
    sl.insertNode('3rd')

    #탐색
    print("<위치 탐색>")
    result = sl.searchNode('1st')
    print("1st의 위치 : {}".format(result))

    result = sl.searchNode('555')
    print("555의 위치 : {}".format(result))
