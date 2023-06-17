# 3085 사탕 게임
# https://www.acmicpc.net/problem/3085
import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
board = []
answer = 0

# 행, 열 체크
def Check(N):
    global answer
    # 행
    for i in range(N):
        cnt = 1
        for j in range(N-1):
            if board[i][j] == board[i][j+1]:
                cnt += 1
                answer = max(answer, cnt)
            else:
                cnt = 1

    # 열
    for i in range(N):
        cnt = 1
        for j in range(N-1):
            if board[j][i] == board[j+1][i]:
                cnt += 1
                answer = max(answer, cnt)
            else:
                cnt = 1

for _ in range(N):
    board.append(list(input()))

# 완탐 시작
# 먼저 가로(행) 부터 검사
for i in range(N):
    for j in range(N-1):
        if board[i][j] != board[i][j+1]:
            # 스와프
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
            Check(N)
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]

# 세로(열)
for i in range(N):
    for j in range(N-1):
        if board[j][i] != board[j+1][i]:
            board[j][i], board[j+1][i] = board[j+1][i], board[j][i]
            Check(N)
            board[j][i], board[j+1][i] = board[j+1][i], board[j][i]

print(answer)