# 23882 알고리즘 수업 - 선택 정렬 2
# https://www.acmicpc.net/problem/23882
import sys

input = sys.stdin.readline


def solution(n, k, a):
    cnt = 0
    flag = 0

    for i in range(n-1, 0, -1):
        lastIdx = i  # 가장 큰수
        for j in range(i):
            if a[j] > a[lastIdx]:
                lastIdx = j
        if lastIdx != i:
            a[lastIdx], a[i] = a[i], a[lastIdx]
            cnt += 1

            if cnt == k:
                flag = 1
                break
        if flag:
            break

    return a if flag else [-1]


n, k = map(int, input().split())
a = list(map(int, input().split()))

print(*solution(n, k, a))
