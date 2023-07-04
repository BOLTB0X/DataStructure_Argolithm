# 1697 숨바꼭질
# https://www.acmicpc.net/problem/1697
import sys
from collections import deque
def input(): return sys.stdin.readline().rstrip()


N, K = map(int, input().split())  # 넣어줌
dist = [0] * 100001
que = deque()
answer = 0

# BFS
que.append(N)
dist[N] = 1

while que:
    cur = que.popleft()

    if cur == K:
        answer = dist[K] - 1
        break

    if cur + 1 < 100001 and not dist[cur+1]:
        que.append(cur + 1)
        dist[cur+1] = dist[cur] + 1

    if cur - 1 >= 0 and not dist[cur-1]:
        que.append(cur - 1)
        dist[cur-1] = dist[cur] + 1

    if 2*cur < 100001 and not dist[2*cur]:
        que.append(cur * 2)
        dist[cur*2] = dist[cur] + 1


print(answer)
