# 연속한 숫자의 곱을 구하는 알고리즘
# 입력: n
# 출력: 1부터 n까지 연속한 숫자를 곱한 값

def fact(n):
    f = 1                      # 곱을 계산할 변수, 초깃값은 1
    for i in range(1, n + 1):  # 1부터 n까지 반복(n + 1은 제외)
        f = f * i              # 곱셈 연산으로 수정
    return f

print(fact(1))                 # 1! = 1
print(fact(5))                 # 5! = 120
print(fact(10))                # 10! = 3628800




def hello():
    print("hello")
    hello()    # hello( ) 함수 안에서 다시 hello( )를 호출

#hello()        # hello( ) 함수를 호출
#재귀엔 모두 종료조건 필요. if not -> RecursionError or Stack Overflow Error




def fact(n):
    if n <= 1:
        return 1
    return n * fact(n - 1)

print(fact(1))  # 1! = 1
print(fact(5))  # 5! = 120
print(fact(10)) # 10! = 3628800
"""
4!
= 4×3!
= 4×3×2!
= 4×3×2×1!
= 4×3×2×1 (1은 종료 조건이므로 재귀 호출을 멈춤)
= 4×3×2 #2x1의 계산값을 반환
= 4×6
= 24
"""


#두가지 펙토리얼 모두 n-1번의 곱셈이 필요함. O(n)

#연습문제1
def prac1(n):
    if(n<1):
        return 0
    return n+prac1(n-1)
print(prac1(10))

#연습문제2_이해를 못했음 최댓값찾기 재귀 호출
    
