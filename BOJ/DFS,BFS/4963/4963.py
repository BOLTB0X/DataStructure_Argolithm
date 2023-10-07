# 4963 섬의 개수
# https://www.acmicpc.net/problem/4963

import sys
sys.setrecursionlimit(10000)
def input(): return sys.stdin.readline().rstrip()


def solution(w, h):
    answer = 0
    board = [list(map(int, input().split())) for _ in range(h)]
    visited = [[False] * w for _ in range(h)]
    dir = [[1, 0], [0, 1], [-1, 0], [0, -1],
           [1, -1], [1, 1], [-1, -1], [-1, 1]]

    def DFS(x, y):
        for d in dir:
            nx = x + d[0]
            ny = y + d[1]

            if nx < 0 or ny < 0 or nx >= h or ny >= w:
                continue

            if visited[nx][ny] or board[nx][ny] == 0:
                continue

            visited[nx][ny] = True
            DFS(nx, ny)

    for i in range(h):
        for j in range(w):
            if board[i][j] == 1 and not visited[i][j]:
                answer += 1
                visited[i][j] = True
                DFS(i, j)

    print(answer)
    return


while True:
    w, h = map(int, input().split())

    if w == 0 and h == 0:
        break

    solution(w, h)
