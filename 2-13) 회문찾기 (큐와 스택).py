#큐(queue)_FIFO, 인규(enqueue), 디규(dequeue)
#스택(stack)_LIFO, 푸시(push), 팝(pop)

# 주어진 문장이 회문인지 아닌지 찾기(큐와 스택의 특징을 이용)
# 입력: 문자열 s
# 출력: 회문이면 True, 아니면 False

def palindrome(s):
    # 큐와 스택을 리스트로 정의
    qu = []
    st = []
    # 1단계: 문자열의 알파벳 문자를 각각 큐와 스택에 넣음
    for x in s:
        # 해당 문자가 알파벳이면(공백, 숫자, 특수문자가 아니면)
        # 큐와 스택에 각각 그 문자를 추가
        if x.isalpha():
            qu.append(x.lower())#저장은 같게 하지만,
            st.append(x.lower())
    # 2단계: 큐와 스택에 들어 있는 문자를 꺼내면서 비교
    while qu: # 큐에 문자가 남아 있는 동안 반복
        if qu.pop(0) != st.pop(): # 큐와 스택에서 꺼낸 문자가 다르면 회문이 아님
            return False#pop에서 큐와 스택 성질 적용
    return True

print(palindrome("Wow"))
print(palindrome("Madam, I’m Adam."))
print(palindrome("Madam, I am Adam."))

"""error...import
from collections import deque
qu=decue()
qu.append(1)

print(qu)
"""
#리스트로 큐를 만들면 디큐 시 한칸 씩 이동해야해서 비효율적..
#대신 스택은 상관없음..
