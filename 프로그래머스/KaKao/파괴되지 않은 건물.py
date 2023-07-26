# 2022 KAKAO BLIND RECRUITMENT 파괴되지 않은 건물
def solution(board, skill):
    answer = 0
    row, col = len(board)+1, len(board[0])+1
    tmp = [[0] * col for _ in range(row)]

    for (t, x1, y1, x2, y2, p) in skill:
        tmp[x1][y1] += p if t == 2 else -p
        tmp[x1][y2+1] += -p if t == 2 else p
        tmp[x2+1][y1] += -p if t == 2 else p
        tmp[x2+1][y2+1] += p if t == 2 else -p

    for i in range(row-1):
        for j in range(col-1):
            tmp[i][j+1] += tmp[i][j]

    for j in range(col-1):
        for i in range(row-1):
            tmp[i+1][j] += tmp[i][j]

    for i in range(row-1):
        for j in range(col-1):
            board[i][j] += tmp[i][j]
            if board[i][j] > 0:
                answer += 1
    return answer
