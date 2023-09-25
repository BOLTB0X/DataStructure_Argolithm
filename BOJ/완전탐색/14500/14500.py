# 14500 테트로미노
# https://www.acmicpc.net/problem/14500
import sys
input = sys.stdin.readline

res = 0


def solution(N, M, board):
    answer = 0
    visited = [[False] * M for _ in range(N)]  # 방문리스트
    dir = [[1, 0], [-1, 0], [0, -1], [0, 1]]

    def specialShape(x, y):
        global res

        for i in range(4):
            tot = board[x][y]
            for j in range(3):
                k = (i+j) % 4
                nx = x + dir[k][0]
                ny = y + dir[k][1]

                if nx < 0 or ny < 0 or nx >= N or ny >= M:
                    continue

                tot += board[nx][ny]
            res = max(res, tot)
        return

    def commonShape(x, y, tot, depth):
        global res
        if depth == 3:
            res = max(res, tot)
            return

        for d in dir:
            nx = x + d[0]
            ny = y + d[1]

            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue

            if visited[nx][ny]:
                continue

            visited[nx][ny] = True
            commonShape(nx, ny, tot+board[nx][ny], depth+1)
            visited[nx][ny] = False
        return

    # 완전탐색 시작
    for i in range(N):
        for j in range(M):
            specialShape(i, j)
            visited[i][j] = True
            commonShape(i, j, board[i][j], 0)
            visited[i][j] = False

    answer = res
    return answer


N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
print(solution(N, M, board))
