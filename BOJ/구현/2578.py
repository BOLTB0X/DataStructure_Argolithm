# 2578 빙고
# https://www.acmicpc.net/problem/2578

import sys

input = lambda: sys.stdin.readline().rstrip()

board = [list(map(int, input().split())) for _ in range(5)] # 격자판

comms = [] # 명령어
for _ in range(5):
    comms += list(map(int, input().split()))

# 가로 체크
def checkRow():
    # 먼저 가로에 빙고가 있는지 확인
    for i in range(5):
        x = 0
        for j in range(5):
            if board[i][j] == -1:
                x += 1
        if x == 5: # 빙고가 나왔다면
            return True
    return False

# 세로 빙고 확인
def checkCol():
    for i in range(5):
        x = 0
        for j in range(5):
            if board[j][i] == -1:
                x += 1
        if x == 5: # 빙고가 나왔다면
            return True
    return False

# 대각선
def checkDiagonal():
    x = 0
    for i in range(5):
        if board[i][i] == -1:
            x += 1
    return True if x == 5 else False

# 역대각선
def checkRdiagonal():
    x = 0
    for i in range(5):
        if board[i][4-i] == -1:
            x += 1
    
    return True if x == 5 else False

# 빙고가 나왔는지 확인
def checkBingo():
    check = 0
    # 먼저 가로에 빙고가 있는지 확인
    for b in board:
        if b.count(-1) == 5:
            check += 1

    # 세로
    for i in range(5):
        x = 0
        for j in range(5):
            if board[j][i] == -1:
                x += 1
        if x == 5:
            check += 1
        
    # 대각선
    x = 0
    for i in range(5):
        if board[i][i] == -1:
            x += 1
    if x == 5:
        check += 1

    # 반대 대각선
    x = 0
    for i in range(5):
        if board[i][4 - i] == -1:
            x += 1
    if x == 5:
        check += 1
    
    return True if check >= 3 else False

def solution():
    cnt = 0
    for k in range(25):
        for i in range(5):
            for j in range(5):
                if comms[k] == board[i][j]:
                    board[i][j] = -1
                    cnt += 1
        if cnt >= 12 and checkBingo(): # 빙고의 조건이 5개가 지워진 거니
            return (k+1) # 사회자가 말했을 때 외쳐야하므로

print(solution())