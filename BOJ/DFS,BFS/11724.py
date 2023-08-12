# 11724 연결 요소의 개수
# https://www.acmicpc.net/problem/11724
import sys
input = sys.stdin.readline
sys.setrecursionlimit(1001)

N, M = map(int, input().split())
adj = [[] * (N+1) for _ in range(N+1)]
visited = [False] * (N+1)
answer = 0


def DFS(cur):
    visited[cur] = True

    for next in adj[cur]:
        if visited[next]:
            continue

        DFS(next)


for _ in range(M):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

    adj[a].sort()
    adj[b].sort()

for i in range(1, N+1):
    if not visited[i]:
        answer += 1
        DFS(i)

print(answer)
