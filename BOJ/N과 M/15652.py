# 15651 N과 M (4)
# https://www.acmicpc.net/problem/15652
import sys
def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())
combi = []


def DFS(N, M, arr, cur):
    if len(arr) == M:
        combi.append(arr.copy())
        return

    for i in range(cur, N+1):
        arr.append(i)
        DFS(N, M, arr, i)
        arr.pop()
    return


DFS(N, M, [], 1)
for c in combi:
    print(*c)
