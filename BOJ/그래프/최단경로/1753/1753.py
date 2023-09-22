# 1753 최단경로
# https://www.acmicpc.net/problem/1753

import sys
import heapq
input = sys.stdin.readline


def dijkstra(start):
    pq = []
    heapq.heappush(pq, (0, start))
    dist[start] = 0

    while pq:
        curD, curP = heapq.heappop(pq)

        if dist[curP] < curD:
            continue

        for v, w in adj[curP]:
            newCost = curD + w

            if newCost < dist[v]:
                dist[v] = newCost
                heapq.heappush(pq, (newCost, v))


V, E = map(int, input().split())
K = int(input())
dist = [10**9]*(V+1)
adj = [[] for _ in range(V+1)]

for _ in range(E):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))

dijkstra(K)

for d in dist[1:]:
    print(d if d != 10**9 else "INF")
