# 19532 수학은 비대면강의입니다
# https://www.acmicpc.net/problem/19532

def solution(a, b, c, d, e, f):
    for x in range(-999, 1000):
        for y in range(-999, 1000):
            temp1 = a*x+b*y
            temp2 = d*x+e*y

            if temp1 == c and temp2 == f:
                return [x, y]
    return []


a, b, c, d, e, f = list(map(int, input().split()))

print(*solution(a, b, c, d, e, f))
