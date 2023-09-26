# 1946 신입사원
# https://www.acmicpc.net/problem/1946
import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    applys = [list(map(int, input().split())) for _ in range(N)]
    answer = 0

    applys.sort(key=lambda x: x[0])

    minCmp = 0

    for i in range(N):
        if i == 0:
            answer += 1
            minCmp = applys[i][1]
        elif applys[i][1] < minCmp:
            answer += 1
            minCmp = applys[i][1]
    print(answer)
