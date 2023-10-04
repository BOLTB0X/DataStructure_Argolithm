# 2563 색종이
# https://www.acmicpc.net/problem/2563
import sys

input = sys.stdin.readline

board = [[0] * 100 for _ in range(100)]
answer = 0

N = int(input())
for _ in range(N):
    x, y = map(int,input().split())

    for i in range(y+10):
        for j in range(x+10):
            board[i][j] = 1

for i in range(100):
    for j in range(100):
        if board[i][j]:
            answer += 1

print(answer)