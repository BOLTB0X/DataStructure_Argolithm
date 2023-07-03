# 7569 토마토
# https://www.acmicpc.net/problem/7569
import sys
from collections import deque


def input():
    return sys.stdin.readline().rstrip()


M, N, H = map(int, input().split())
board = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]
dir = [[0, 0, 1], [0, 0, -1], [1, 0, 0],
       [-1, 0, 0], [0, 1, 0], [0, -1, 0]]
que = deque()
answer = -1

# 큐에 토마토 위치 넣어줌
for i in range(H):
    for j in range(N):
        for k in range(M):
            if board[i][j][k] == 1:
                que.append((i, j, k))

# BFS 시작
while que:
    cz, cx, cy = que.popleft()

    for d in dir:
        nz = cz + d[0]
        nx = cx + d[1]
        ny = cy + d[2]

        if ny < 0 or nx < 0 or nz < 0 or nz >= H or ny >= M or nx >= N:
            continue

        if board[nz][nx][ny] == -1:  # 벽인 경우
            continue

        if board[nz][nx][ny]:
            continue

        board[nz][nx][ny] = board[cz][cx][cy] + 1
        que.append((nz, nx, ny))

flag = 0
# 안익은 토마토 찾기
for i in range(H):
    for j in range(N):
        for k in range(M):
            if board[i][j][k] == 0:
                answer = -1
                flag = 1
                break
            answer = max(answer, board[i][j][k] - 1)
        if flag:
            break
    if flag:
        break

print(answer)
