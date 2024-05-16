# 2979 트럭 주차
# https://www.acmicpc.net/problem/2979
import sys

input = sys.stdin.readline


def getFee(a, b, c, carCount):
    if carCount == 1:
        return a
    elif carCount == 2:
        return b
    return c


def solution(a, b, c, cmd):
    res = [0, 0, 0, 0]
    timeArr = [0 for _ in range(100)]

    for i in range(3):
        for j in range(cmd[i][0], cmd[i][1]):
            timeArr[j] += 1

    for i in range(100):
        if timeArr[i] == 3:
            res[3] += 1
        elif timeArr[i] == 2:
            res[2] += 1
        elif timeArr[i] == 1:
            res[1] += 1

    return (res[1]*a) + (2*res[2]*b) + (3*res[3]*c)


a, b, c = map(int, input().split())
cmd = [list(map(int, input().split())) for _ in range(3)]

print(solution(a, b, c, cmd))
# 8 3 3 10
