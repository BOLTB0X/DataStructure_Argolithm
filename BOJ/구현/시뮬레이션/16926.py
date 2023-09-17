# 16926 배열 돌리기 1
# https://www.acmicpc.net/problem/16926

import sys
input = sys.stdin.readline

N, M, R = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

for _ in range(R):
    for i in range(min(N, M)//2):
        x, y = i, i
        tmp = board[x][y]

        # 좌측 (0,0) -> (N,0)
        for j in range(i+1, N-i):
            x = j
            prevValue = board[x][y]
            board[x][y] = tmp
            tmp = prevValue

        # 아래 (N,0) -> (N, M)
        for j in range(i+1, M-i):
            y = j
            prevValue = board[x][y]
            board[x][y] = tmp
            tmp = prevValue

        # 우측 (N, M) -> (0, M)
        for j in range(i+1, N-i):
            x = N-j-1
            prevValue = board[x][y]
            board[x][y] = tmp
            tmp = prevValue

        # 위 (0, M) -> (0, 0)
        for j in range(i+1, M-i):
            y = M-j-1
            prevValue = board[x][y]
            board[x][y] = tmp
            tmp = prevValue

for i in range(N):
    print(*board[i])
