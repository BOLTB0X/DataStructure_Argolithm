# 2606 바이러스
# https://www.acmicpc.net/problem/2606
import sys
input = lambda : sys.stdin.readline().rstrip()

pathList = []
N = int(input())
M = int(input())
adj = [[] * i for i in range(N+1)] # 인접리스트
visited = [False] * (N+1) # 방문리스트

for _ in range(M):
    a, b = map(int,input().split())
    adj[a].append(b)
    adj[b].append(a)

# 깊이 우선 탐색
def DFS(cur):
    for n in adj[cur]:
        if visited[n]:
            continue

        visited[n] = True
        pathList.append(n)
        DFS(n) # 호출

visited[1] = True
DFS(1)
#print(*pathList)
print(len(pathList))
