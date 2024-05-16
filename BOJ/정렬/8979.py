# 올림픽 8979
# https://www.acmicpc.net/problem/8979
import sys

input = sys.stdin.readline


def solution(n, k, medals):
    res = 0

    medals.sort(key=lambda x: (x[1], x[2], x[3]), reverse=True)
    idx = [medals[i][0] for i in range(n)].index(k)

    for i in range(n):
        if medals[idx][1:] == medals[i][1:]:
            res = i+1
            break

    return res


n, k = map(int, input().split())
medals = [list(map(int, input().split())) for _ in range(n)]

print(solution(n, k, medals))
