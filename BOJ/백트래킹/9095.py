# 9095 1, 2, 3 더하기
# https://www.acmicpc.net/problem/9095
import sys
def input(): return sys.stdin.readline().rstrip()


T = int(input())


def recur(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    if n == 3:
        return 4
    else:
        return recur(n-1) + recur(n-2) + recur(n-3)


for _ in range(T):
    n = int(input())
    result = recur(n)
    print(result)
