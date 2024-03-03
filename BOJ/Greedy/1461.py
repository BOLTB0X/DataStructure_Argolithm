# 1461 도서관
# https://www.acmicpc.net/problem/1461
import sys

input = sys.stdin.readline


def solution(n, m, books):
    ret = 0
    plus, minus, maxDist = [], [], 0

    for i in range(n):
        if books[i] > 0:
            plus.append(books[i])
        else:
            minus.append(books[i])

        if abs(maxDist) < abs(books[i]):
            maxDist = books[i]

    plus.sort(reverse=True)
    minus.sort()

    for i in range(0, len(plus), m):
        if plus[i] == maxDist:
            continue
        ret += plus[i]

    for i in range(0, len(minus), m):
        if minus[i] == maxDist:
            continue
        ret += abs(minus[i])

    return ret * 2 + abs(maxDist)


n, m = map(int, input().split())
books = list(map(int, input().split()))

print(solution(n, m, books))
