# 11660 구간 합 구하기 5
# https://www.acmicpc.net/problem/11660
import sys
def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
cmds = [list(map(int, input().split())) for _ in range(M)]

tmp = [[0] * (N+1) for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, N+1):
        tmp[i][j] = board[i-1][j-1] + tmp[i-1][j] + tmp[i][j-1] - tmp[i-1][j-1]

for cmd in cmds:
    print(tmp[cmd[2]][cmd[3]] + tmp[cmd[0]-1][cmd[1]-1] -
          tmp[cmd[2]][cmd[1]-1] - tmp[cmd[0]-1][cmd[3]])
