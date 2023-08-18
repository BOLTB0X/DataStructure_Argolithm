import sys
sys.setrecursionlimit(10**4)

answer = ""
board = [["."] * 51 for _ in range(51)]
dir = [[1, 0], [0, -1], [0, 1], [-1, 0]]
dirCmd = ["d", "l", "r", "u"]


def DFS(n, m, r, c, k, cx, cy, cur, depth):
    global answer
    if answer or abs(cx-r)+abs(cy-c)+depth > k or depth > k:
        return

    if depth == k and board[cx][cy] == "E":
        answer = cur
        return

    for i in range(4):
        nx = cx + dir[i][0]
        ny = cy + dir[i][1]

        if nx < 1 or ny < 1 or nx > n or ny > m:
            continue

        DFS(n, m, r, c, k, nx, ny, cur+dirCmd[i], depth+1)

    return


def solution(n, m, x, y, r, c, k):
    global answer

    if abs(x-r)+abs(y-c) > k or (k-abs(x-r)+abs(y-c)) % 2 == 1:
        answer = "impossible"
    else:
        board[x][y] = "S"
        board[r][c] = "E"
        DFS(n, m, r, c, k, x, y, "", 0)

    return answer if answer else "impossible"
