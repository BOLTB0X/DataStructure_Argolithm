# 15651 N과 M (3)
# https://www.acmicpc.net/problem/15651
import sys
def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())
per = []


def DFS(N, M, arr):
    if len(arr) == M:
        per.append(arr.copy())
        return

    for i in range(1, N+1):
        arr.append(i)
        DFS(N, M, arr)
        arr.pop()
    return


DFS(N, M, [])

for p in per:
    print(*p)
