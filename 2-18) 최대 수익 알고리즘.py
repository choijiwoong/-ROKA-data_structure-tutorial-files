# 주어진 주식 가격을 보고 얻을 수 있는 최대 수익을 구하는 알고리즘
# 입력: 주식 가격의 변화 값(리스트: prices)
# 출력: 한 주를 한 번 사고팔아 얻을 수 있는 최대 수익 값

def max_profit(prices):
    n = len(prices)
    max_profit = 0 # 최대 수익은 항상 0 이상의 값_손실의 경우 안판다는 전제
    for i in range(0, n - 1):
        for j in range(i + 1, n):
            # i날에 사서 j날에 팔았을 때 얻을 수 있는 수익
            profit = prices[j] - prices[i]
            # 이 수익이 지금까지 최대 수익보다 크면 값을 고침
            if profit > max_profit:
                max_profit = profit
    return max_profit

stock = [10300, 9600, 9800, 8200, 7800, 8300, 9500, 9800, 10200, 9500]
print(max_profit(stock))

#위는 모든 경우의 수를 모두 비교하여 비효율적.
#그냥 파는 날을 기준으로 그 전의 최소 주가를 찾아보자
#O(n^2)


# 주어진 주식 가격을 보고 얻을 수 있는 최대 수익을 구하는 알고리즘
# 입력: 주식 가격의 변화 값(리스트: prices)
# 출력: 한 주를 한 번 사고팔아 얻을 수 있는 최대 수익 값

def max_profit_(prices):
    n = len(prices)
    max_profit = 0         # 최대 수익은 항상 0 이상의 값
    min_price = prices[0]  # 첫째 날의 주가를 주가의 최솟값으로 기억

    for i in range(1, n):  # 1부터 n - 1까지 반복
        # 지금까지의 최솟값에 주식을 사서 i날에 팔 때의 수익
        profit = prices[i] - min_price
        if profit > max_profit:    # 이 수익이 지금까지 최대 수익보다 크면 값을 고침
            max_profit = profit
        if prices[i] < min_price:  # i날 주가가 최솟값보다 작으면 값을 고침
            min_price = prices[i]
    return max_profit

stock = [10300, 9600, 9800, 8200, 7800, 8300, 9500, 9800, 10200, 9500]
print(max_profit_(stock))


#O(n)

import time
import random

def test(n):
    # 테스트 자료 만들기(5000부터 20000까지의 난수를 주가로 사용)
    a = []
    for i in range(0, n):
        a.append(random.randint(5000, 20000))
    # 느린 O(n * n) 알고리즘 테스트
    start = time.time()       # 계산 시작 직전 시각을 기억
    mps = max_profit(a)  # 계산 수행
    end = time.time()         # 계산 시작 직후 시각을 기억
    time_slow = end - start   # 직후 시각에서 직전 시각을 빼면 계산에 걸린 시간
    # 빠른 O(n) 알고리즘 테스트
    start = time.time()       # 계산 시작 직전 시각을 기억
    mpf = max_profit_(a)  # 계산 수행
    end = time.time()         # 계산 시작 직후 시각을 기억
    time_fast = end - start   # 직후 시각에서 직전 시각을 빼면 계산에 걸린 시간
    # 결과 출력: 계산 결과
    print(n, mps, mpf)  # 입력 크기, 각각 알고리즘이 계산한 최대 수익 값(같아야 함)
    # 결과 출력: 계산 시간 비교
    m = 0 # 느린 알고리즘과 빠른 알고리즘의 수행 시간 비율을 저장할 변수
    if time_fast > 0:  # 컴퓨터 환경에 따라 빠른 알고리즘 시간이 0으로 측정될 수 있음
                       # 이럴 때는 0을 출력
        m = time_slow / time_fast # 느린 알고리즘 시간 / 빠른 알고리즘 시간
    # 입력 크기, 느린 알고리즘 수행 시간, 빠른 알고리즘 수행 시간, 계산 시간 차이
    # %d는 정수 출력, %.5f는 소수점 다섯 자리까지 출력을 의미
    print("%d %.5f %.5f %.2f" % (n, time_slow, time_fast, m))

test(100)
test(10000)

# test(100000) # 수행 시간이 오래 걸리므로 일단 주석 처리
