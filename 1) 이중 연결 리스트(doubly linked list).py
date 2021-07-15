#이중 연결 리스트
class DLinkedList:

    #D_L_list에서 쓸 노드
    class Node:
        def __init__(self, v, n=None, p=None):
            self.value=v#저장된 데이터
            self.next=n#다음 노드 가리키는 변수
            self.prev=p#이전 노드 가리키는 변수

    #D_L_List에서 필요한 변수
    def __init__(self):
        self.head=None#첫 생서시 내부에는 노드가 없음
        self.tail=None

    #head로 삽입. v: 데이터
    def insertNodeBefore(self, v):
        #없을 경우
        if self.head is None:
            self.head=self.Node(v)
            self.tail=self.head#같은 노드를 가리킴
        else:
            #self.head: 기존노드, self.head.prev: 기존 노드의 prev
            self.head.prev=self.Node(v,n=self.head)#1,2번을 동시수행(현재 head가 가리키는 기존 노드의 prev를
                                                   #새로 생성하는 노드로 지정, 새로 생성한 노드의 next를 기존 노드로 지정)
            #self.head.prev: 기존 노드의 prev=새 노드
            self.head=self.head.prev#3. head를 새로운 노드로 변경
            

    #tail로 삽입, v: 데이터
    def insertNodeAfter(self, v):
        #없을 경우
        if self.tail is None:
            self.tail=self.Node(v)
            self.head=self.tail#같은 노드를 가리킴
        else:
            #self.tail : 기존노드, self.tail.next: 기존 노드의 next
            self.tail.next=self.Node(v,p=self.tail)#1,2번을 동시수행(현재 tail가 가리키는 기존 노드의 next를
                                                   #새로 생성하는 노드로 지정 새로 생성한 노드의 prev를 기존 노드로 지정
            #self.tail.next: 기존노드이 next==새로운 노드
            self.tail=self.tail.next#tail를 새로운 노드로 변경

    def printNodeBefore(self):
        #데이터가 없을 때
        if self.head is None:
            print("저장된 데이터가 없음")
            return
        else:
            print("<현재 리스트 구조>", end='\t')#end로 마지막 개행 탭
            link=self.head#처음은 head를 지정, 이후부터 현 노드의 next를 지정

            #link가 가리키는 노드가 없을 때까지 반복
            #none, 0, ""는는 조건판단에서 False로 처리, 그 외는 True로 처리
            while link:
                print(link.value,'<->',end= ' ')
                link=link.next#link를 현 위치 노드의 next로 변경
            print()#줄바꿈

    def printNodeAfter(self):
        #데이터가 없을 때
        if self.tail is None:
            print("저장된 데이터가 없음")
            return
        else:
            print("<현재 리스트 구조>",end='\t')
            link=self.tail

            while link:
                print(link.value,'<->', end=' ')
                link=link.prev#link의 현 위치 노드의 prev로 변경
            print()#줄바꿈

    #head로 삭제
    def deleteNodeBefore(self):
        #없을 경우->스킵
        if self.tail is None:
            print("삭제할 노드가 없습니다.")
            return
        else:
            #1. 현재 head가 가리키는 노드의 next를 새로운 head로 지정
            self.head=self.head.next
            #2. 새로운 head의 prev를 None으로 변경
            self.head.prev=None

    #tail로 삭제
    def deleteNodeAfter(self):
        #없을 경우 ->스킵
        if self.tail is None:
            print("삭제할 노드가 없습니다.")
            return
        else:
            #1. 현재 tail이 가리키는 노드의 prev를 새로운 tail로 지정
            self.tail=self.tail.prev
            #2. 새로운 head의 prev를 None으로 변경
            self.tail.next=None

    #head로 조회(탐색)
    def searchNodeBefore(self, v):
        #데이터가 없을 때
        if self.head is None:
            prnit("저장된 데이터가 없음")
            return
        else:
            link=self.head#처음은 head를 지정. 이후부터는 현 노드의 next를 지정
            index=0#몇 번째 노드인지 확인
            while link:
                #내가 찾는 노드인가
                if v==link.value:
                    return index#위치를 반환
                else:
                    link=link.next#link를 현 위치 노드의 next로 변경
                    index+=1
            #여기까지 왔다 == 해당 v값을 가진 노드가 없다.

    #tail로 조회(탐색)
    def searchNodeAfter(self, v):
        #데이터가 없을 때
        if self.tail is None:
            pritn("저장된 데이터가 없음")
            return
        else:
            link=self.tail
            index=0#몇 번째 노드인지 기록
            while link:
                #내가 찾는 노드인지 확인
                if v==link.value:
                    return index#위치를 반환
                else:
                    link=link.prev#link를 현 위치 노드의 prev로 변경
                    index-=1#위치값 -1감소
            #여기까지 왔다==해당 v값을 가진 노드가 없다.
        

            
##test
if __name__=="__main__":
    dl = DLinkedList()
    dl.insertNodeBefore('1stF')
    dl.insertNodeAfter('1stB')
    dl.insertNodeBefore('2ndF')
    dl.insertNodeAfter('2ndB')
    dl.printNodeBefore()

    # head로 탐색
    print("<head로 위치 탐색>")
    result = dl.searchNodeBefore('2ndF')
    print("2ndF 위치 : {}".format(result))

    result = dl.searchNodeBefore('1stF')
    print("1stF 위치 : {}".format(result))

    # tail로 탐색
    print("<tail로 위치 탐색>")
    result = dl.searchNodeAfter('2ndB')
    print("2ndB 위치 : {}".format(result))

    result = dl.searchNodeAfter('1stF')
    print("1stF 위치 : {}".format(result))
