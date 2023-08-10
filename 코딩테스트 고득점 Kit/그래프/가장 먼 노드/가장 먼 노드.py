import heapq


def solution(n, edge):
    answer = 0

    adj = [[] for _ in range(n+1)]
    dist = [float('inf')] * (n+1)

    for e in edge:
        adj[e[0]].append(e[1])
        adj[e[1]].append(e[0])

    # 다익스트라
    pq = []
    heapq.heappush(pq, [0, 1])
    dist[1] = 0

    while pq:
        d, cur = heapq.heappop(pq)

        if dist[cur] < d:
            continue

        for next in adj[cur]:
            if d + 1 >= dist[next]:
                continue
            dist[next] = d+1
            heapq.heappush(pq, [d+1, next])

    answer = dist[1:].count(max(dist[1:]))
    return answer
