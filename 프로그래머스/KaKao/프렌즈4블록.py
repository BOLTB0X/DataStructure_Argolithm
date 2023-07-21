# 2018 KAKAO BLIND RECRUITMENT [1차] 프렌즈4블록
from collections import deque


def solution(m, n, board):
    answer = 0
    board = [list(b) for b in board]  # 각 행을 리스트로 변환
    que = deque()  # 터트릴 블록의 시작점들

    while True:
        for i in range(m):
            for j in range(n):
                if board[i][j] != "X" and squareCheck(board, i, j, board[i][j]):
                    que.append((i, j))

        if len(que) == 0:
            break

        while que:
            cy, cx = que.popleft()
            if board[cy][cx] != "X":
                board[cy][cx] = "X"
                answer += 1
            if board[cy+1][cx] != "X":
                board[cy+1][cx] = "X"
                answer += 1
            if board[cy][cx+1] != "X":
                board[cy][cx+1] = "X"
                answer += 1
            if board[cy+1][cx+1] != "X":
                board[cy+1][cx+1] = "X"
                answer += 1

        board = boardUpdate(board, m, n)
    return answer


def squareCheck(board, y, x, chType):
    if y + 1 >= len(board) or board[y+1][x] != chType:
        return False
    if x + 1 >= len(board[0]) or board[y][x+1] != chType:
        return False
    if board[y+1][x+1] != chType:
        return False
    return True


def boardUpdate(board, m, n):
    for i in range(m-1, 0, -1):
        for j in range(n):
            if board[i][j] == "X":
                for k in range(i-1, -1, -1):
                    if board[k][j] != "X":
                        board[i][j], board[k][j] = board[k][j], "X"
                        break

    return board
