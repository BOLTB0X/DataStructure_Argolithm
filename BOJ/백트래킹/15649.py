# 15649 N과 M (1)
# https://www.acmicpc.net/problem/15649
import sys
input = lambda : sys.stdin.readline().rstrip()

# dfs로 순열
def DFS(N, M, visited, arr, level):
    if level == M:
        for a in arr:
            print(a, end= " ")
        print()
        return
    
    for i in range(1,N+1):
        if visited[i]: # 재방문
            continue

        arr.append(i)
        visited[i] = True
        DFS(N, M, visited, arr, level+1)
        visited[i] = False # 백트래킹을 위한
        arr.pop()

N,M = map(int,input().split())
visited = [False] * (N+1) # 방문리스트

DFS(N,M, visited, [], 0)