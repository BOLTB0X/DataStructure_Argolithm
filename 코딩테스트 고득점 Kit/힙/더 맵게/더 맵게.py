import heapq


def solution(scoville, K):
    answer = 0
    pq = []

    for s in scoville:
        heapq.heappush(pq, s)

    while pq[0] < K:
        heapq.heappush(pq, heapq.heappop(pq) + heapq.heappop(pq) * 2)
        answer += 1

        if len(pq) == 1 and pq[0] < K:
            answer = -1
            break

    return answer
