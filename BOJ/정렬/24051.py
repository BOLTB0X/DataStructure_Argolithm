# 24051 알고리즘 수업 - 삽입 정렬 1
# https://www.acmicpc.net/problem/24051
import sys

input = sys.stdin.readline


def solution(n, k, a):
    res, cnt = 0, 0

    for i in range(1, n):
        loc = i-1
        newItem = a[i]

        while loc >= 0 and newItem < a[loc]:
            a[loc+1] = a[loc]
            loc -= 1
            cnt += 1
            if cnt == k:
                res = a[loc+1]

        if loc + 1 != i:
            a[loc+1] = newItem
            cnt += 1
            if cnt == k:
                res = a[loc+1]

    return res if cnt >= k else -1


n, k = map(int, input().split())
a = list(map(int, input().split()))

print(solution(n, k, a))
