# 2178 미로 탐색
# https://www.acmicpc.net/problem/2178
import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
board = []  # 격자판
dist = [[0] * M for _ in range(N)]  # 방문리스트
dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]  # 방향

for _ in range(N):
    board.append(input())

que = deque()
que.append((0, 0))
dist[0][0] = 1

while que:
    cy, cx = que.popleft()

    for d in dir:
        ny = cy + d[0]
        nx = cx + d[1]

        if ny < 0 or nx < 0 or ny >= N or nx >= M:
            continue

        if dist[ny][nx] != 0 or board[ny][nx] == "0":
            continue

        dist[ny][nx] = dist[cy][cx] + 1
        que.append((ny, nx))

print(dist[N-1][M-1])
