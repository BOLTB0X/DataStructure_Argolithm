# 1931 회의실 배정
# https://www.acmicpc.net/problem/1931

import sys
input = sys.stdin.readline


def solution(n, info):
    ret = 0

    info.sort(key=lambda x: (x[1], x[0]))
    currentEnding = info[0][1]
    ret += 1

    for i in range(1, n):
        if info[i][0] >= currentEnding:
            currentEnding = info[i][1]
            ret += 1

    return ret


n = int(input())
info = [list(map(int, input().split())) for _ in range(n)]

print(solution(n, info))
