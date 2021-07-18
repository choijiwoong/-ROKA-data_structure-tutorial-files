#꼭짓점(vertex), 선(edge)
#딕셔너리로 표현.
#친구를 출력하는데에 앞으로 처리해야 할 사람을 넣어두었다가 하나씩 꺼내기 위한 기억장소로 큐를 사용

# 친구 리스트에서 자신의 모든 친구를 찾는 알고리즘
# 입력: 친구 관계 그래프 g, 모든 친구를 찾을 자신 start
# 출력: 모든 친구의 이름

def print_all_friends(g, start):
    qu = []       # 기억 장소 1: 앞으로 처리해야 할 (사람 이름, 친밀도) 튜플을 큐에 저장
    done = set()  # 기억 장소 2: 이미 큐에 추가한 사람을 집합에 기록(중복 방지)

    qu.append((start, 0))   # (사람 이름, 친밀도) 정보를 하나의 튜플로 묶어 처리
                            # 자기 자신의 친밀도: 0
    done.add(start)         # 집합에도 추가

    while qu:               # 큐에 처리할 사람이 남아 있는 동안
        (p, d) = qu.pop(0)  # 큐에서 (사람 이름, 친밀도) 정보를 p와 d로 각각 꺼냄
        print(p, d)         # 사람 이름과 친밀도를 출력
        for x in g[p]:      # 친구들 중에
            if x not in done:          # 아직 큐에 추가된 적이 없는 사람을
                qu.append((x, d + 1))  # 친밀도를 1 증가시켜 큐에 추가하고
                done.add(x)            # 집합에도 추가
                
# 친구 관계 리스트
# A와 B가 친구이면
# A의 친구 리스트에도 B가 나오고, B의 친구 리스트에도 A가 나옴

fr_info = {
    'Summer': ['John', 'Justin', 'Mike'],
    'John': ['Summer', 'Justin'],
    'Justin': ['John', 'Summer', 'Mike', 'May'],
    'Mike': ['Summer', 'Justin'],
    'May': ['Justin', 'Kim'],
    'Kim': ['May'],
    'Tom': ['Jerry'],
    'Jerry': ['Tom']
}

print_all_friends(fr_info, 'Summer')
print()
print_all_friends(fr_info, 'Jerry')

#그래프에 연결된 모든 꼭짓점을 탐색하는 알고리즘으로 '그래프 탐색 알고리즘'이라고 불림.

#연습문제

def prac(data, target):
    qu=[]#FIFO순으로 처리할 규 정의
    done=set()#그냥 {}라고 하면 dictionary로 받아 오류생길수도.

    qu.append((target, 0))#큐에 첫 손님 target 넣어버려~
    done.add(target)#집합에도 넣어버려~ 약간 집합은 예외리스트 느낌0

    while qu:#뭐가 있느냐!
        (name, rate)=qu.pop(0)#팝팝!해서 저장해부러라!
        print(name, rate)#출력하시라요~
        for x in data[name]:#딕셔너리에 이름 존재 데스까?
            if x not in done:#추가 안된거 있으까?
                qu.append((x,rate+1))#추가해부러~
                done.add(x)#부리부리대마왕~~
    
data={
    1:[2,3],
    2:[1,4,5],
    3:[1],
    4:[2],
    5:[2]
}
prac(data, 3)
