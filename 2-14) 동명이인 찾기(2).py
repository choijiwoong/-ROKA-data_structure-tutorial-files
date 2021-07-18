# 두 번 이상 나온 이름 찾기
# 입력: 이름이 n개 들어 있는 리스트
# 출력: n개의 이름 중 반복되는 이름의 집합

def find_same_name(a):
    # 1단계: 각 이름이 등장한 횟수를 딕셔너리로 만듦
    name_dict = {}
    for name in a:                # 리스트 a에 있는 자료들을 차례로 반복
        if name in name_dict:     # 이름이 name_dict에 있으면
            name_dict[name] += 1  # 등장 횟수를 1 증가
        else:                     # 새 이름이면
            name_dict[name] = 1   # 등장 횟수를 1로 저장
    # 2단계: 만들어진 딕셔너리에서 등장 횟수가 2 이상인 것을 결과에 추가
    result = set()          # 결괏값을 저장할 빈 집합
    for name in name_dict:  # 딕셔너리 name_dict에 있는 자료들을 차례로 반복
        if name_dict[name] >= 2:
            result.add(name)
    return result

name = ["Tom", "Jerry", "Mike", "Tom"] # 대소문자 유의: 파이썬은 대소문자를 구분함
print(find_same_name(name))
name2=["Tom", "Jerry", "Mike", "Tom", "Mike"]
print(find_same_name(name2))


#위는 O(n). 기본적으로 반복문이 중첩되면 O(n^2)꼴-> for반복문이 겹치느냐 안겹치느냐의 차이가 큼

#위의 방법은 모든 사람을 서로 비교하는 방법보다 더 나은 시간복잡도를 가지지만, 딕셔너리를 만들어 등장횟수를 저장
#해야하기 때문에 더 많은 저장공간을 사용하게 됨. -> 공간 복잡도를 희생하여 시간복잡도를 개선한 경우.

#정확한 알고리즘 분석은 시간복잡도, 공간복잡도를 모두 고려해야 하지만, 
#대체로 저장공간이 크기 때문에 공간 복잡도에 덜 민감한 편.

#연습문제
def prac(data, target):
    if target not in data:
        return '?'
    else:
        return data[target]

alldata={39:"Justin", 14:"John", 67: "Mike", 105:"Summer"}
print(prac(alldata,16))

#딕셔너리처럼 key와 value를 대응시켜 자료를 보관하는 바료구조를 해시 테이블(hash table)이라고 부른다. 
#C++에선 언오더드맵(unordered_map), 자바에선 해시맵(hashmap)이라고 부름.
#효율성이 상당히 높은 자료구조.
