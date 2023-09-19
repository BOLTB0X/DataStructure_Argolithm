# 16935 배열 돌리기 3
# https://www.acmicpc.net/problem/16935
import sys
input = sys.stdin.readline

N, M, R = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

cmd = list(map(int, input().split()))


def one():  # 상하 반전
    tmp = [[0] * M for _ in range(N)]
    for i in range(N):
        tmp[i] = arr[N-1-i]
    return tmp


def two():  # 좌우 반전
    tmp = [[0] * M for _ in range(N)]

    for i in range(N):
        for j in range(M):
            tmp[i][j] = arr[i][M-1-j]

    return tmp


def three():  # 오른쪽 90
    tmp = [[0] * N for _ in range(M)]

    for i in range(M):
        for j in range(N):
            tmp[i][j] = arr[N-1-j][i]

    return tmp


def four():  # 왼쪽 90
    tmp = [[0] * N for _ in range(M)]

    for i in range(M):
        for j in range(N):
            tmp[i][j] = arr[j][M-1-i]

    return tmp


def five():
    tmp = [[0] * M for _ in range(N)]

    # 1 -> 2
    for i in range(N // 2):
        for j in range(M // 2):
            tmp[i][j + M // 2] = arr[i][j]

    # 2 -> 3
    for i in range(N // 2):
        for j in range(M // 2, M):
            tmp[i + N // 2][j] = arr[i][j]

    # 3 -> 4
    for i in range(N // 2, N):
        for j in range(M // 2, M):
            tmp[i][j - M // 2] = arr[i][j]

    # 4 -> 1
    for i in range(N // 2, N):
        for j in range(M // 2):
            tmp[i - N // 2][j] = arr[i][j]

    return tmp


def six():
    tmp = [[0] * M for _ in range(N)]

    # 1 -> 4
    for i in range(N // 2):
        for j in range(M // 2):
            tmp[i + N // 2][j] = arr[i][j]

    # 4 -> 3
    for i in range(N // 2, N):
        for j in range(M // 2):
            tmp[i][j + M // 2] = arr[i][j]

    # 3 -> 2
    for i in range(N // 2, N):
        for j in range(M // 2, M):
            tmp[i - N // 2][j] = arr[i][j]

    # 2 -> 1
    for i in range(N // 2):
        for j in range(M // 2, M):
            tmp[i][j - M // 2] = arr[i][j]

    return tmp


for c in cmd:
    if c == 1:
        arr = one()
    elif c == 2:
        arr = two()
    elif c == 3:
        arr = three()
        N, M = M, N
    elif c == 4:
        arr = four()
        N, M = M, N
    elif c == 5:
        arr = five()
    elif c == 6:
        arr = six()

for a in arr:
    print(*a)
