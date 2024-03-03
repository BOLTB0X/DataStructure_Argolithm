# 11399 ATM
# https://www.acmicpc.net/problem/11399
import sys

input = sys.stdin.readline


def solution(n, p):
    ret = 0
    tot = 0

    p.sort()
    for i in range(n):
        tot += p[i]
        ret += tot

    return ret


n = int(input())
p = list(map(int, input().split()))

print(solution(n, p))
