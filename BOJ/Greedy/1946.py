# 1946 신입 사원
# https://www.acmicpc.net/problem/1946
import sys

input = sys.stdin.readline


def solution(n, applicants):
    ret = 1

    applicants.sort(key=lambda x: x[0])
    cmp = applicants[0][1]

    for i in range(1, n):
        if applicants[i][1] < cmp:
            ret += 1
            cmp = applicants[i][1]

    return ret


t = int(input())

for _ in range(t):
    n = int(input())
    applicants = [list(map(int, input().split())) for _ in range(n)]
    print(solution(n, applicants))
