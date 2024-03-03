# 24267 알고리즘 수업 - 알고리즘의 수행 시간 6
# https://www.acmicpc.net/problem/24266
import sys

input = sys.stdin.readline


def MenOfPassion(A, n):
    tot = 0

    for i in range(1, n-2):
        for j in range(i+1, n-1):
            for k in range(j+1, n):
                tot = tot + (A[i] * A[j] * A[k])

    # (n - 2) * (n - 1) * n / 6
    return tot


n = int(input())
print((n-2)*(n-1)*n//6)
print(3)
