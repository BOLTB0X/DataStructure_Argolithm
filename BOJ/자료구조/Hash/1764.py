# 1764 듣보잡
# https://www.acmicpc.net/problem/1764

import sys
input = sys.stdin.readline


def solution(n, m, noListen, noSee):
    noListenSeeDic = {}

    for name in noListen:
        if name in noListenSeeDic:
            noListenSeeDic[name] += 1
        else:
            noListenSeeDic[name] = 1

    for name in noSee:
        if name in noListenSeeDic:
            noListenSeeDic[name] += 1
        else:
            noListenSeeDic[name] = 1

    filtedList = sorted(
        list(
            filter(lambda key: noListenSeeDic[key] >= 2, noListenSeeDic.keys())
        )
    )

    print(len(filtedList))
    for fl in filtedList:
        print(fl)


n, m = map(int, input().split())

noListen = [input().rstrip() for _ in range(n)]
noSee = [input().rstrip() for _ in range(m)]

solution(n, m, noListen, noSee)
