# 쉽게 설명한 선택 정렬
# 입력: 리스트 a
# 출력: 정렬된 새 리스트
# 주어진 리스트에서 최솟값의 위치를 돌려주는 함수

def find_min_idx(a):
    n = len(a)
    min_idx = 0
    for i in range(1, n):
        if a[i] < a[min_idx]:
            min_idx = i
    return min_idx
 
def sel_sort(a):
    result = []  # 새 리스트를 만들어 정렬된 값을 저장
    while a:     # 주어진 리스트에 값이 남아 있는 동안 계속
        min_idx = find_min_idx(a)  # 리스트에 남아 있는 값 중 최솟값의 위치
        value = a.pop(min_idx)     # 찾은 최솟값을 빼내어 value에 저장
        result.append(value)       # value를 결과 리스트 끝에 추가
    return result
 
d = [2, 4, 5, 1, 3]
print(sel_sort(d))


# 선택 정렬
# 입력: 리스트 a
# 출력: 없음(입력으로 주어진 a가 정렬됨

def sel_sort_upgrade(a):
    n = len(a)
    for i in range(0, n - 1): # 0부터 n -2까지 반복
        # i번 위치부터 끝까지 자료 값 중 최솟값의 위치를 찾음
        min_idx = i
        for j in range(i + 1, n):
            if a[j] < a[min_idx]:
                min_idx = j
        # 찾은 최솟값을 i번 위치로
        a[i], a[min_idx] = a[min_idx], a[i]

d = [2, 4, 5, 1, 3]
sel_sort_upgrade(d)
print(d)


#리스트 안의 자료를 한번씩 보는 것과 같으니 n(n-1)/2번 해야하니 O(n^2)->입력이 많아질수록 시간더 오래걸림

