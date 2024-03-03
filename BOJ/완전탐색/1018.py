# 1018 체스판 다시 칠하기
# https://www.acmicpc.net/problem/1018

def Countting_BW(i, j, board, ret):
    startWhiteCount = 0  # 시작이 W, W가 아니면 고치는 갯수
    startBlackCount = 0  # 시작이 B, B가 아니면 고치는 갯수

    for k in range(i, i+8):
        for l in range(j, j+8):
            if not (k+l) % 2:
                if board[k][l] == 'B':
                    startWhiteCount += 1
                if board[k][l] == 'W':
                    startBlackCount += 1
            else:
                if board[k][l] == 'B':
                    startBlackCount += 1
                if board[k][l] == 'W':
                    startWhiteCount += 1

    return min(ret, min(startWhiteCount, startBlackCount))


def solution(n, m, board):
    ret = n*m

    for i in range(n-7):
        for j in range(m-7):
            ret = min(ret, Countting_BW(i, j, board, ret))

    return ret


n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]
print(solution(n, m, board))
