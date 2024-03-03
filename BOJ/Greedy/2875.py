# 2875 대회 or 인턴
# https://www.acmicpc.net/problem/2875

import sys

input = sys.stdin.readline


def solution(n, m, k):
    ret = 0

    while n >= 2 and m >= 1 and n+m >= k+3:
        n -= 2
        m -= 1
        ret += 1

    return ret


n, m, k = map(int, input().split())
print(solution(n, m, k))
