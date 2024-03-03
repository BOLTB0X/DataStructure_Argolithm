# 16200 해커톤
# https://www.acmicpc.net/problem/16200
import sys
input = sys.stdin.readline


def solution(n, x):
    ret = 0

    x.sort()
    team = []
    teamLength = 0
    teamLimit = 0

    for i in range(n):
        if not team:
            teamLimit = x[i]

        team.append(x[i])
        teamLength += 1

        if teamLimit == teamLength:
            ret += 1
            teamLimit = 0
            teamLength = 0
            team = []

    if team:
        ret += 1

    return ret


n = int(input())
x = list(map(int, input().split()))

print(solution(n, x))
