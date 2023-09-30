# 1051 숫자 정사각형
# https://www.acmicpc.net/problem/1051
import sys

input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(input()) for _ in range(N)]

answer = -1
maxLangth = max(N, M)

for l in range(maxLangth):
    for i in range(N-l):
        for j in range(M-l):
            if board[i][j] == board[i+l][j] and board[i][j] == board[i][j+l] and board[i][j] == board[i+l][j+l]:
                answer = max(answer, (l+1)**2)

print(answer)