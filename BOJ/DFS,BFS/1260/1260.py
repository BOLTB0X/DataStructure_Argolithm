# 1260 DFS와 BFS
# https://www.acmicpc.net/problem/1260

import sys
from collections import deque
input = lambda: sys.stdin.readline().rstrip()

# dfs 깊이우선 탐색
def DFS(graph, cur, visited):
    visited[cur] = True # 방문처리
    print(cur, end=' ')

    for next in graph[cur]:
        if not visited[next]: # 미방문 발견
            DFS(graph, next, visited)

#bfs 너비우선 탐색
def BFS(graph,cur,visited):
    que = deque([cur])
    visited[cur]=True

    while que:
        v = que.popleft()
        print(v, end = ' ') # 출력

        for i in graph[v]: # dfs와 동일하게
            if not visited[i]:
                que.append(i)
                visited[i] = True

n,m,v = map(int,input().split())
graph = [[] for _ in range(n+1)]
visited = [False]*(n+1)

for i in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()

DFS(graph, v, visited) # dfs
print()

visited=[False]*(n+1)
BFS(graph, v, visited) # bfs