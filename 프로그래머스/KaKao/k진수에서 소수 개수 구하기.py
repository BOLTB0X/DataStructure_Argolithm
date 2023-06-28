# 2022 KAKAO BLIND RECRUITMENT k진수에서 소수 개수 구하기
# level 2
import math

# k진수 변환


def transValue(n, k):
    ret = ""

    while n > 0:
        ret += str(n % k)
        n //= k

    return ret[::-1]  # 뒤집어서 반환

# 소수 판별


def isPrime(number):
    if number == 0 or number == 1:
        return False
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True


def solution(n, k):
    answer = 0
    ret = transValue(n, k)
    tmp = ""

    for r in ret:  # 0을 기준으로 쪼개줌
        if r == "0":  # 앞에 숫자가 소수인지 체크
            if len(tmp) > 0 and isPrime(int(tmp)):
                answer += 1  # 카운트
            tmp = ""  # 초기화
        else:
            tmp += r

    if len(tmp) > 0 and isPrime(int(tmp)):  # 남아 있는 경우
        answer += 1
    return answer
