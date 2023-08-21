# 13913 숨바꼭질 4
# https://www.acmicpc.net/problem/13913
import sys
from collections import deque
input = sys.stdin.readline

MAX = 100001


def viewPath(dist, move, cur):
    path = []
    tmp = cur

    for _ in range(dist[cur]+1):
        path.append(tmp)
        tmp = move[tmp]

    print(*path[::-1])
    return


def solution(N, K):
    dist = [0] * MAX
    move = [0] * MAX

    que = deque()
    que.append(N)

    while que:
        cur = que.popleft()

        if cur == K:
            print(dist[cur])
            viewPath(dist, move, cur)
            break

        for next in [cur-1, cur+1, cur*2]:
            if next >= 0 and next < MAX and not dist[next]:
                que.append(next)
                dist[next] = dist[cur] + 1
                move[next] = cur

    return


N, K = map(int, input().split())

solution(N, K)
