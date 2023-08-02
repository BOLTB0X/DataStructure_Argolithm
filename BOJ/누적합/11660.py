# 11660 구간 합 구하기 5
# https://www.acmicpc.net/problem/11660
import sys
def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
prefixsum = [[0] * (N+1) for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, N+1):
        prefixsum[i][j] = board[i-1][j-1] + prefixsum[i-1][j] + \
            prefixsum[i][j-1] - prefixsum[i-1][j-1]

for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    print(prefixsum[x2][y2]-prefixsum[x1-1][y2] -
          prefixsum[x2][y1-1]+prefixsum[x1-1][y1-1])
