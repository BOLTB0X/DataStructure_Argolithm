# 4396 지뢰 찾기
# https://www.acmicpc.net/problem/4396
import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
board = [list(map(str, input())) for _ in range(N)]  
openBoard = [list(map(str, input())) for _ in range(N)] 
flag = False # 지뢰가 있는 칸이 열렸다면 지뢰가 있는 모든 칸이 별표(*)로 

# 갯수 확인 메소드
def checkCnt(x, y):
    cnt = 0 
    
    if x+1 < N and board[x+1][y] == "*":
        cnt += 1
    if x-1 >= 0 and board[x-1][y] == "*":
        cnt += 1
    if y+1 < N and board[x][y+1] == "*":
        cnt += 1
    if y-1 >= 0 and board[x][y-1] == "*":
        cnt += 1

    if x+1 < N and y+1 < N and board[x+1][y+1] == "*":
        cnt += 1
    if x-1 >= 0 and y-1 >= 0 and board[x-1][y-1] == "*":
        cnt += 1
    if x+1 < N and y-1 >= 0 and board[x+1][y-1] == "*":
        cnt += 1
    if x-1 >= 0 and y+1 < N and board[x-1][y+1] == "*":
        cnt += 1    

    return cnt

# 보드 업데이트
def updateBoard():
    for i in range(N):
        for j in range(N):
            if board[i][j] == "*":
                openBoard[i][j] = "*" # 지뢰 표시
    return

for i in range(N):
    for j in range(N):
        if openBoard[i][j] == "x":
            if board[i][j] == "*": # 재수없게 지뢰가 있다면
                openBoard[i][j] = "*"
                flag = True # 체크
                continue 

            openBoard[i][j] = str(checkCnt(i,j))

if flag: # 만약 지뢰를 밟았다면
    updateBoard()

for i in range(N):
    for j in range(N):
        print(openBoard[i][j], end="")
    print()
