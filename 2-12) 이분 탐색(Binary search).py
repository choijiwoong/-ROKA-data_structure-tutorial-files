# 리스트에서 특정 숫자 위치 찾기(이분 탐색)
# 입력: 리스트 a, 찾는 값 x
# 출력: 찾으면 그 값의 위치, 찾지 못하면 -1
 
def binary_search(a, x):
    # 탐색할 범위를 저장하는 변수 start, end
    # 리스트 전체를 범위로 탐색 시작(0 ~ len(a) -1)
    start = 0
    end = len(a) - 1
 
    while start <= end:            # 탐색할 범위가 남아 있는 동안 반복
        mid = (start + end) // 2   # 탐색 범위의 중간 위치
        if x == a[mid]:           # 발견!
            return mid
        elif x > a[mid]:           # 찾는 값이 더 크면 오른쪽으로 범위를 좁혀 계속 탐색
            start = mid + 1
        else:                      # 찾는 값이 더 작으면 왼쪽으로 범위를 좁혀 계속 탐색
            end = mid - 1
    return -1                      # 찾지 못했을 때

d = [1, 4, 9, 16, 25, 36, 49, 64, 81]
print(binary_search(d, 36))
print(binary_search(d, 50))

#이분탐색은 O(logn)으로 순차탐색의 복잡도인 O(n)보다 훨신 효율적임.
#미리 정렬되어 있어야 한다는 번거로움 but, 필요한 값을 여러번 찾아야 한다면 좋음.

#연습문제

def prac(array, target, start, end):
    mid=(start+end)//2
    if start>end or mid>=end:#mid추가는 mid list sizeover error..
        return -1
    if array[mid]==target:
        return mid
    elif array[mid]>target:
        return prac(array, target, start, mid-1)#재귀함수 return은 항상 까먹지 말자...무한반복에러 왜나나 했네...
    else:
        return prac(array,target, mid+1,end)
    

d = [1, 4, 9, 16, 25, 36, 49, 64, 81]#이진탐색의 전제는 정렬된 배열************
print(prac(d, 81, 0, len(d)))
