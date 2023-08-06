# 11403 경로 찾기
# https://www.acmicpc.net/problem/11403
import sys
def input(): return sys.stdin.readline().rstrip()


N = int(input())
adj = [list(map(int, input().split())) for _ in range(N)]

for k in range(N):
    for a in range(N):
        for b in range(N):
            if adj[a][k] and adj[k][b]:
                adj[a][b] = 1

for i in range(N):
    print(*adj[i])
