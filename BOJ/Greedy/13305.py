# 13305 주유소
# https://www.acmicpc.net/problem/13305
import sys

input = sys.stdin.readline


def solution(n, dist, prices):
    ret = 0
    cur = float('inf')

    for i in range(n-1):
        if cur > prices[i]:
            cur = prices[i]
        ret += (cur*dist[i])

    return ret


n = int(input())
dist = list(map(int, input().split()))
prices = list(map(int, input().split()))

print(solution(n, dist, prices))
