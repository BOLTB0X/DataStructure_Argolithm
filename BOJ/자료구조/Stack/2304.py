# 2304 창고 다각형
# https://www.acmicpc.net/problem/2304
import sys

input = sys.stdin.readline


def solution(n, info):
    answer = 0

    info.sort()
    maxHeight = -1
    maxIndex = 0
    for i in range(n):
        if info[i][1] > maxHeight:
            maxHeight = info[i][1]
            maxIndex = i

    curHeight = info[0]
    for i in range(1, maxIndex+1):
        if info[i][1] >= curHeight[1]:
            answer += (curHeight[1]*(info[i][0]-curHeight[0]))
            curHeight = info[i]

    curHeight = info[n-1]
    for i in range(n-2, maxIndex-1, -1):
        if info[i][1] >= curHeight[1]:
            answer += (curHeight[1]*(curHeight[0]-info[i][0]))
            curHeight = info[i]

    return answer + maxHeight


n = int(input())
info = [list(map(int, input().split())) for _ in range(n)]

print(solution(n, info))
