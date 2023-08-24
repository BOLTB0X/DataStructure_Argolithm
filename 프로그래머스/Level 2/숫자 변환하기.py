from collections import deque


def solution(x, y, n):
    answer = -1
    que = deque()
    dist = [0] * 1000001

    que.append(x)
    dist[x] = 1

    while que:
        cur = que.popleft()

        if cur == y:
            answer = dist[cur] - 1
            break

        for next in [cur+n, cur*2, cur*3]:
            if next < 1 or next > 1000001:
                continue

            if next > y or dist[next] != 0:
                continue

            dist[next] = dist[cur] + 1
            que.append(next)

    return answer
