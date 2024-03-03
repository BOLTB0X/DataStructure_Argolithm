# 24265 알고리즘 수업 - 알고리즘의 수행 시간 4
# https://www.acmicpc.net/problem/24265
import sys

input = sys.stdin.readline


def MenOfPassion(A, n):
    tot = 0

    for i in range(1, n):
        for j in range(i+1, n+1):
            tot = tot + (A[i] * A[j])

    # 시간복잡도 : (n - 1) * n / 2
    return tot


n = int(input())
print((n - 1)*n//2)
print(2)
