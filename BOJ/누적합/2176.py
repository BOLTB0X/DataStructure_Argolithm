# 2176 2차원 배열의 합
# https://www.acmicpc.net/problem/2167
import sys
def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
prefixsum = [[0] * (M+1) for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, M+1):
        prefixsum[i][j] = board[i-1][j-1] + prefixsum[i-1][j] + \
            prefixsum[i][j-1] - prefixsum[i-1][j-1]


T = int(input())

for _ in range(T):
    x1, y1, x2, y2 = map(int, input().split())
    print(prefixsum[x2][y2] - prefixsum[x1-1][y2] -
          prefixsum[x2][y1-1] + prefixsum[x1-1][y1-1])
