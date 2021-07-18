# 최대공약수 구하기
# 입력: a, b
# 출력: a와 b의 최대공약수

def gcd(a, b):
    i = min(a, b)  # 두 수 중에서 최솟값을 구하는 파이썬 함수
    while True:
        if a % i == 0 and b % i == 0:
            return i
        i = i - 1   # i를 1만큼 감소시킴

 
print(gcd(1, 5))   # 1
print(gcd(3, 6))   # 3
print(gcd(60, 24)) # 12
print(gcd(81, 27)) # 27





# 최대공약수 구하기
# 입력: a, b
# 출력: a와 b의 최대공약수
def gcd(a, b):
    if b == 0:           # 종료 조건
        return a
    return gcd(b, a % b)  # 좀 더 작은 값으로 자기 자신을 호출

print(gcd(1, 5))          # 1
print(gcd(3, 6))          # 3
print(gcd(60, 24))        # 12
print(gcd(81, 27))        # 27
"""
gcd(60, 24)
→ gcd(24, 12)
    → gcd(12, 0)
        → 12 (b가 0이므로 종료 조건)
    → 12 #남은 값들 반환
→ 12 (최종 결과)
"""

#연습문제. 피보나치 수열을 재귀로_답지봄. 7번값=5번값+6번값.*********************
def pibohile(n):
    if(n<=1):
        return n
    return pibohile(n-1)+pibohile(n-2)

print(pibohile(7))
