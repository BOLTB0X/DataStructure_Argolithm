# 16927 배열 돌리기 2
# https://www.acmicpc.net/problem/16927

import sys
input = sys.stdin.readline

N, M, R = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
p = 0  # 시작 위치


def rotate(sx, sy):
    size = (N-1)*2+(M-1)*2


for _ in range(min(N, M)//2):
    rotate(p, p)
    p += 1
    N -= 2
    M -= 2


for a in arr:
    print(" ".join(map(str, a)))
