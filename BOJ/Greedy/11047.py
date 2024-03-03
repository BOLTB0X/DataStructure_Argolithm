# 11047 동진 0
# https://www.acmicpc.net/problem/11047
import sys
input = sys.stdin.readline


def solution(n, k, coins):
    ret = 0

    coins.sort(reverse=True)
    for i in range(n):
        if k < coins[i]:
            continue

        ret += (k//coins[i])
        k %= coins[i]

    return ret


n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]

print(solution(n, k, coins))
