# 24266 알고리즘 수업 - 알고리즘의 수행 시간 5
# https://www.acmicpc.net/problem/24266
import sys

input = sys.stdin.readline


def MenOfPassion(A, n):
    tot = 0

    for i in range(1, n+1):
        for j in range(1, n+1):
            for k in range(1, n+1):
                tot = tot + (A[i] * A[j] * A[k])

    return tot


n = int(input())
print(n**3)
print(3)
